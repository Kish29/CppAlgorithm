//
// Created by 蒋澳然 on 2021/7/9.
//

#include "timemeasure/TimeMeasure.h"


template<class Key, class Value, class Hash = std::hash<Key>>
class threadsafe_query_table {

private:

    class bucket_type {

    private:
        typedef std::pair<Key, Value> bucket_value;
        typedef std::list<bucket_value> bucket_data;
        typedef typename bucket_data::iterator bucket_iterator;

        bucket_data data{};
        mutable boost::shared_mutex s_mtx;

        bucket_iterator find_entry_for(const Key &key) const {
            return std::find_if(data.begin(), data.end(), [&](const bucket_value &item) -> bool {
                item.first == key;
            });
        }

    public:
        Value value_for(const Key &key, const Value &default_value) const {
            read_lock lck(s_mtx);
            const bucket_iterator entry = find_entry_for(key);
            return entry == data.end() ? default_value : entry->second;
        }

        void add_or_update_mapping(const Key &key, const Value &value) {
            write_lock lck(s_mtx);
            const bucket_iterator entry = find_entry_for(key);
            if (entry == data.end()) {
                data.push_back(bucket_value{key, value});
            } else {    // update value
                entry->second = value;
            }
        }

        void remove_mapping(const Key &key) {
            write_lock lck(s_mtx);
            const bucket_iterator entry = find_entry_for(key);
            if (entry == data.end()) return;
            data.erase(entry);
        }

    };

    vector<unique_ptr<bucket_type>> buckets{};
    Hash hasher{};

    bucket_type &get_bucket(const Key &key) const {
        const size_t bucket_index = hasher(key) % buckets.size();
        // nullptr ???
        return *buckets[bucket_index];
    }

public:

    typedef Key key_type;
    typedef Value mapped_type;

    typedef Hash hash_type;

    explicit threadsafe_query_table(
            unsigned buckets_num = 19, const Hash &hasher_ = Hash()) :
            buckets(buckets_num), hasher(hasher_) {
        for (int i = 0; i < buckets_num; ++i) {
            buckets.at(i) = std::make_unique<bucket_type>(new bucket_type);
        }
    }

    threadsafe_query_table(const threadsafe_query_table &other) = delete;

    threadsafe_query_table &operator=(const threadsafe_query_table &other) = delete;

    Value value_for(const Key &key, const Value &default_value = Value()) const {
        return get_bucket(key).value_for(key, default_value);
    }

    void add_or_update_mapping(const Key &key, const Value &value) {
        get_bucket(key).add_or_update_mapping(key, value);
    }

    void remove_mapping(const Key &key) {
        get_bucket(key).remove_mapping(key);
    }
};

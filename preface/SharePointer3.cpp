//
// Created by 蒋澳然 on 2021/7/6.
//

#include "TimeMeasure.h"

#include "fcntl.h"
#include "cerrno"   // for errno
#include "sys/mman.h"  // for share memory

class ShareMemoryDetacher {

public:

    void operator()(int *p) {
        cout << "unlink tmp1234" << endl;
        if (shm_unlink("tmp1234") != 0) {
            std::cerr << "OOPS: shm_unlink() failed" << endl;
        }
    }

};

shared_ptr<int> getSharedIntMemory(off_t num) {
    void *mem;
    int shmfd = shm_open("tmp1234", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        throw std::string(strerror(errno));
    }
    if (ftruncate(shmfd, num * (off_t) sizeof(int)) == -1) {
        throw std::string(strerror(errno));
    }
    mem = mmap(nullptr, num * (off_t) sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (mem == MAP_FAILED) {
        throw std::string(strerror(errno));
    }
    return shared_ptr<int>(static_cast<int *>(mem), ShareMemoryDetacher());
}
// Thread.cc

#include "Thread.hh"
#include "define.hh"

#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <semaphore>

void threadFunc(unsigned int threadNumber, unsigned int sleepTime) {
    pprint("Running thread number " + std::to_string(threadNumber));
    pprint("Sleeping for " + std::to_string(sleepTime) + " seconds");
    std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
}

void demoThread() {
    section("Thread");
    unsigned int numberOfThreads = 5;
    std::vector<std::thread> threadList;

    // Create threads
    for (unsigned int i = 0; i < numberOfThreads; i++) {
        std::thread threadObj(threadFunc, i, i);
        threadList.push_back(std::move(threadObj));
    }

    // Close threads
    for (std::vector<std::thread>::reverse_iterator it = threadList.rbegin() ; it != threadList.rend() ; ++it) {
        it->join();
    }

    pprint("Finish executing all threads");
}

// Demo mutex
std::mutex mtx;
int shared_var = 0;

void mtxDemoFunc(int threadNum) {
    mtx.lock();
    for (int i = 0; i < 10; i++) {
        shared_var++;
        pprint("thread " + std::to_string(threadNum) + " - shared_var = " + std::to_string(shared_var));
        pprint("sleeping...");
        sleep(2);
    }
    mtx.unlock();
}

void demoMutex() {
    section("Mutex");
    std::thread thread1(mtxDemoFunc, 1);
    std::thread thread2(mtxDemoFunc, 2);
    thread1.join();
    thread2.join();
    pprint("final shared_var = " + std::to_string(shared_var));
}

// Demo counting semaphore
std::counting_semaphore<10> count_sem(3);

void countingSemaphoreWorker(int threadNum) {
    count_sem.acquire();
    pprint("Thread " + std::to_string(threadNum) + " acquired sem");

    for (int i = 0; i < 1000000; i++) {
        shared_var++;
    }
    pprint("Thread " + std::to_string(threadNum) + " - shared_var = " + std::to_string(shared_var));

    count_sem.release();
    pprint("Thread " + std::to_string(threadNum) + " released sem");
}

void demoCountingSemaphore() {
    section("Counting Semaphore");
    std::thread thread1(countingSemaphoreWorker, 1);
    std::thread thread2(countingSemaphoreWorker, 2);
    std::thread thread3(countingSemaphoreWorker, 3);
    thread1.join();
    thread2.join();
    thread3.join();
    pprint("final shared_var = " + std::to_string(shared_var));
}

// Demo binary semaphore
int shared_var_2 = 0;
std::binary_semaphore bin_sem(1);

void binarySemaphoreWorker(int threadNum) {
    bin_sem.acquire();
    pprint("Thread " + std::to_string(threadNum) + " acquired sem");

    for (int i = 0; i < 1000000; i++) {
        shared_var_2++;
    }
    pprint("Thread " + std::to_string(threadNum) + " - shared_var_2 = " + std::to_string(shared_var_2));

    bin_sem.release();
    pprint("Thread " + std::to_string(threadNum) + " released sem");
}

void demoBinarySemaphore() {
    section("Binary Semaphore");
    std::thread thread1(binarySemaphoreWorker, 1);
    std::thread thread2(binarySemaphoreWorker, 2);
    std::thread thread3(binarySemaphoreWorker, 3);
    thread1.join();
    thread2.join();
    thread3.join();
    pprint("final shared_var_2 = " + std::to_string(shared_var_2));
}

// #include <iostream>
// #include <memory> // Include memory for unique_ptr
// #include "InMemoryCache.h"
// #include "FIFO.h"
// #include "LRU.h"
// #include "LIFO.h"

// void testFIFOCache() {
//     std::cout << "Testing FIFO Cache:" << std::endl;
//     std::unique_ptr<InMemoryCache<int, std::string>> fifoCache(
//         new InMemoryCache<int, std::string>(3, std::unique_ptr<FIFOPolicy<int>>(new FIFOPolicy<int>()))
//     );

//     fifoCache->put(1, "one");
//     fifoCache->put(2, "two");
//     fifoCache->put(3, "three");
//     fifoCache->put(4, "four"); // This will evict key 1 ("one")

//     try {
//         std::cout << "Get key 1: " << fifoCache->get(1) << std::endl; // Should throw an exception
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl; // Output: Key not found
//     }

//     std::cout << "Get key 2: " << fifoCache->get(2) << std::endl; // Should print "two"
//     std::cout << "Get key 3: " << fifoCache->get(3) << std::endl; // Should print "three"
//     std::cout << "Get key 4: " << fifoCache->get(4) << std::endl; // Should print "four"
// }

// void testLRUCache() {
//     std::cout << "Testing LRU Cache:" << std::endl;
//     std::unique_ptr<InMemoryCache<int, std::string>> lruCache(
//         new InMemoryCache<int, std::string>(3, std::unique_ptr<LRUCachePolicy<int>>(new LRUCachePolicy<int>()))
//     );

//     lruCache->put(1, "one");
//     lruCache->put(2, "two");
//     lruCache->put(3, "three");
//     lruCache->get(1); // Access 1
//     lruCache->put(4, "four"); // This will evict key 2 ("two")

//     try {
//         std::cout << "Get key 2: " << lruCache->get(2) << std::endl; // Should throw an exception
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl; // Output: Key not found
//     }

//     std::cout << "Get key 1: " << lruCache->get(1) << std::endl; // Should print "one"
//     std::cout << "Get key 3: " << lruCache->get(3) << std::endl; // Should print "three"
//     std::cout << "Get key 4: " << lruCache->get(4) << std::endl; // Should print "four"
// }

// void testLIFOCache() {
//     std::cout << "Testing LIFO Cache:" << std::endl;
//     std::unique_ptr<InMemoryCache<int, std::string>> lifoCache(
//         new InMemoryCache<int, std::string>(3, std::unique_ptr<LIFOPolicy<int>>(new LIFOPolicy<int>()))
//     );

//     lifoCache->put(1, "one");
//     lifoCache->put(2, "two");
//     lifoCache->put(3, "three");
//     lifoCache->put(4, "four"); // This will evict key 3 ("three")

//     try {
//         std::cout << "Get key 3: " << lifoCache->get(3) << std::endl; // Should throw an exception
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl; // Output: Key not found
//     }

//     std::cout << "Get key 1: " << lifoCache->get(1) << std::endl; // Should print "one"
//     std::cout << "Get key 2: " << lifoCache->get(2) << std::endl; // Should print "two"
//     std::cout << "Get key 4: " << lifoCache->get(4) << std::endl; // Should print "four"
// }

// void testAdditionalScenarios() {
//     std::cout << "Testing Additional Scenarios:" << std::endl;
//     std::unique_ptr<InMemoryCache<int, std::string>> lruCache(
//         new InMemoryCache<int, std::string>(2, std::unique_ptr<LRUCachePolicy<int>>(new LRUCachePolicy<int>()))
//     );

//     lruCache->put(1, "one");
//     lruCache->put(2, "two");
//     lruCache->get(1); // Access 1
//     lruCache->put(3, "three"); // This will evict key 2 ("two")
//     lruCache->put(4, "four"); // This will evict key 1 ("one")

//     try {
//         std::cout << "Get key 1: " << lruCache->get(1) << std::endl; // Should throw an exception
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl; // Output: Key not found
//     }

//     try {
//         std::cout << "Get key 2: " << lruCache->get(2) << std::endl; // Should throw an exception
//     } catch (const std::exception& e) {
//         std::cout << e.what() << std::endl; // Output: Key not found
//     }

//     std::cout << "Get key 3: " << lruCache->get(3) << std::endl; // Should print "three"
//     std::cout << "Get key 4: " << lruCache->get(4) << std::endl; // Should print "four"
// }

// int main() {
//     testFIFOCache();
//     testLRUCache();
//     testLIFOCache();
//     testAdditionalScenarios();

//     return 0;
// }


#include <iostream>
#include <memory> // Include memory for unique_ptr
#include "InMemoryCache.h"
#include "FIFO.h"
#include "LRU.h"
#include "LIFO.h"

void performCacheOperations(InMemoryCache<int, std::string>& cache) {
    int choice, key;
    std::string value;

    while (true) {
        std::cout << "\nChoose an operation:\n"
                  << "1. Put (key, value)\n"
                  << "2. Get (key)\n"
                  << "3. Remove (key)\n"
                  << "4. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                cache.put(key, value);
                std::cout << "Added (key, value): (" << key << ", " << value << ")" << std::endl;
                break;
            case 2:
                std::cout << "Enter key: ";
                std::cin >> key;
                try {
                    value = cache.get(key);
                    std::cout << "Value for key " << key << " is: " << value << std::endl;
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl; // Output: Key not found
                }
                break;
            case 3:
                std::cout << "Enter key: ";
                std::cin >> key;
                cache.remove(key);
                std::cout << "Removed key: " << key << std::endl;
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }
}

int main() {
    int policyChoice, maxSize;

    std::cout << "Choose an eviction policy:\n"
              << "1. FIFO\n"
              << "2. LRU\n"
              << "3. LIFO\n"
              << "Enter choice: ";
    std::cin >> policyChoice;

    std::cout << "Enter maximum size of the cache: ";
    std::cin >> maxSize;

    switch (policyChoice) {
        case 1: {
            std::unique_ptr<InMemoryCache<int, std::string>> fifoCache(
                new InMemoryCache<int, std::string>(maxSize, std::unique_ptr<FIFOPolicy<int>>(new FIFOPolicy<int>()))
            );
            performCacheOperations(*fifoCache);
            break;
        }
        case 2: {
            std::unique_ptr<InMemoryCache<int, std::string>> lruCache(
                new InMemoryCache<int, std::string>(maxSize, std::unique_ptr<LRUCachePolicy<int>>(new LRUCachePolicy<int>()))
            );
            performCacheOperations(*lruCache);
            break;
        }
        case 3: {
            std::unique_ptr<InMemoryCache<int, std::string>> lifoCache(
                new InMemoryCache<int, std::string>(maxSize, std::unique_ptr<LIFOPolicy<int>>(new LIFOPolicy<int>()))
            );
            performCacheOperations(*lifoCache);
            break;
        }
        default:
            std::cout << "Invalid choice! Exiting program." << std::endl;
            break;
    }

    return 0;
}

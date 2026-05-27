#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int N, M, K;
    cout << "Enter count of elements to INSERT (N): ";
    cin >> N;
    cout << "Enter count of elements to DELETE (M): ";
    cin >> M;
    cout << "Enter count of elements to SEARCH (K): ";
    cin >> K;

    
    map<int, int> regularMap;

    cout << "\n--- Running operations on std::map ---";
    
    
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) regularMap[i] = i;
    auto stop = high_resolution_clock::now();
    auto mapInsertTime = duration_cast<milliseconds>(stop - start).count();

   
    start = high_resolution_clock::now();
    for (int i = 0; i < K; i++) {
        volatile int temp = regularMap.count(i); 
    }
    stop = high_resolution_clock::now();
    auto mapSearchTime = duration_cast<milliseconds>(stop - start).count();

    
    start = high_resolution_clock::now();
    for (int i = 0; i < M; i++) regularMap.erase(i);
    stop = high_resolution_clock::now();
    auto mapDeleteTime = duration_cast<milliseconds>(stop - start).count();

    
    unordered_map<int, int> unorderedMap;

    cout << "\n--- Running operations on std::unordered_map ---";

    
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) unorderedMap[i] = i;
    stop = high_resolution_clock::now();
    auto unMapInsertTime = duration_cast<milliseconds>(stop - start).count();

    
    start = high_resolution_clock::now();
    for (int i = 0; i < K; i++) {
        volatile int temp = unorderedMap.count(i);
    }
    stop = high_resolution_clock::now();
    auto unMapSearchTime = duration_cast<milliseconds>(stop - start).count();

    
    start = high_resolution_clock::now();
    for (int i = 0; i < M; i++) unorderedMap.erase(i);
    stop = high_resolution_clock::now();
    auto unMapDeleteTime = duration_cast<milliseconds>(stop - start).count();

   
    cout << "\n\n================ PERFORMANCE RESULTS ================\n";
    cout << "Operation\tstd::map (ms)\tstd::unordered_map (ms)\n";
    cout << "-----------------------------------------------------\n";
    cout << "Insert (" << N << ")\t" << mapInsertTime << "\t\t" << unMapInsertTime << "\n";
    cout << "Search (" << K << ")\t" << mapSearchTime << "\t\t" << unMapSearchTime << "\n";
    cout << "Delete (" << M << ")\t" << mapDeleteTime << "\t\t" << unMapDeleteTime << "\n";
    cout << "=====================================================\n";

    return 0;
}
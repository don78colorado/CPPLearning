#include "mergeSort.h"
#include <QtTest/QtTest>
#include "util.h"

class TestMergeSort: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    { qDebug("called before everything else"); }
    void arrayMergeSortTest();
    void arrayMergeSortSTLStyleTest();
    void arrayMergeTest();
    void stdArrayMergeSortTest();
    void stdArrayMergeSortSTLStyleTest();
    void stdArrayMergeTest();
    void vectorTest();
    void vectorSTLStyleTest();
    void mergeVectorTest();
    void mergeVectorSTLStyleTest();
    void cleanupTestCase()
    { qDebug("called after all tests"); }
};



void TestMergeSort::arrayMergeSortTest()
{
    int testarray[] = {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    int sortedArray[] = {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    const std::size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    mergeSort(testarray, testArrayLength);
    QVERIFY(std::equal(testarray, testarray+testArrayLength, sortedArray));
}

void TestMergeSort::arrayMergeSortSTLStyleTest()
{
    int testarray[] = {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    int sortedArray[] = {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    const std::size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    mergeSort(testarray, testarray+testArrayLength);
    QVERIFY(std::equal(testarray, testarray+testArrayLength, sortedArray));
}

void TestMergeSort::arrayMergeTest()
{
    int testarray[] = {0,3,11,50,3,6,7,49,81};
    int sortedArray[] = {0,3,3,6,7,11,49,50,81};
    const std::size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    merge(testarray, 3, testArrayLength-1);
    QVERIFY(std::equal(testarray, testarray+testArrayLength, sortedArray));

    const std::size_t vMin = 100;
    const std::size_t vMax = 200;
    const int maxRandomNumber = 25000;
    for (int i = 0; i < 50; ++i) {
        const std::size_t v1Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t v2Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t aLength = v1Length + v2Length;
        std::vector<int> randomVector1;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
                        v1Length, []() { return rand()%(maxRandomNumber+1); });
        std::vector<int> randomVector2;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
                        v2Length, []() { return rand()%(maxRandomNumber+1); });
        std::sort(randomVector1.begin(), randomVector1.end());
        std::sort(randomVector2.begin(), randomVector2.end());
        randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
        int testarray2[aLength];
        std::copy(randomVector1.begin(), randomVector1.end(), testarray2);
        //printIntArray(testarray2, aLength);
        QVERIFY(!std::is_sorted(testarray2, testarray2+aLength));
        merge(testarray2, v1Length-1, aLength-1);
        QVERIFY(std::is_sorted(testarray2, testarray2+aLength));
    }
}

void TestMergeSort::stdArrayMergeSortTest()
{
    std::array<int, 11> testarray {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    std::array<int, 11> sortedarray {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    mergeSort(testarray);
    QCOMPARE(testarray, sortedarray);
}

void TestMergeSort::stdArrayMergeSortSTLStyleTest()
{
    std::array<int, 11> testarray {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    std::array<int, 11> sortedarray {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    mergeSort(testarray.begin(), testarray.end());
    QCOMPARE(testarray, sortedarray);

}

void TestMergeSort::stdArrayMergeTest()
{
    std::array<int, 9> testArray {0,3,11,50,3,6,7,49,81};
    std::array<int, 9>::iterator end1 = testArray.begin();
    end1 = end1 + 3;
    merge(testArray, testArray.begin(), end1);
    QVERIFY(std::is_sorted(testArray.begin(), testArray.end()));

    for (int i = 0; i < 50; ++i) {
        // creat two sorted std::vectors of length 10, combine them into an array and test merge on it
        const std::size_t randomVectorLength = 10;
        const int maxRandomNumber = 10;
        std::vector<int> randomVector1;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
                        randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
        std::vector<int> randomVector2;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
                        randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
        std::sort(randomVector1.begin(), randomVector1.end());
        std::vector<int>::iterator end1 = randomVector1.end();
        std::sort(randomVector2.begin(), randomVector2.end());
        randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
        //print(randomVector1.begin(), randomVector1.end());
        std::array<int, randomVectorLength*2> testarray2;
        std::copy(randomVector1.begin(), randomVector1.end(), testarray2.begin());
        QVERIFY(!std::is_sorted(testarray2.begin(), testarray2.end()));
        merge(testarray2, testarray2.begin(), testarray2.begin()+(randomVectorLength-1));
        QVERIFY(std::is_sorted(testarray2.begin(), testarray2.end()));
    }

}

void TestMergeSort::vectorTest()
{
    int testarray[] = {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    std::vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    std::vector<int> sortedVector{1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    mergeSort(intVector);
    QCOMPARE(intVector,sortedVector);
}

void TestMergeSort::vectorSTLStyleTest()
{
    const std::size_t randomVectorLength = 10;
    const int maxRandomNumber = 100;
    std::vector<int> randomVector;
    do {
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector),
                        randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    } while (std::is_sorted(randomVector.begin(), randomVector.end()));
    QVERIFY(!std::is_sorted(randomVector.begin(), randomVector.end()));
    mergeSort(randomVector.begin(), randomVector.end());
    QVERIFY(std::is_sorted(randomVector.begin(), randomVector.end()));
}

void TestMergeSort::mergeVectorTest()
{
    int testarray[] = {0,3,11,50,3,6,7,49,81};
    std::vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    std::vector<int>::iterator end1 = intVector.begin();
    end1 = end1 + 3;
    merge(intVector, intVector.begin(), end1);
    QVERIFY(std::is_sorted(intVector.begin(), intVector.end()));

    const std::size_t vMin = 100;
    const std::size_t vMax = 200;
    const int maxRandomNumber = 25000;
    for (int i = 0; i < 50; ++i) {
        const std::size_t v1Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t v2Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t aLength = v1Length + v2Length;
        std::vector<int> randomVector1;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
                        v1Length, []() { return rand()%(maxRandomNumber+1); });
        std::vector<int> randomVector2;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
                        v2Length, []() { return rand()%(maxRandomNumber+1); });
        std::sort(randomVector1.begin(), randomVector1.end());
        std::sort(randomVector2.begin(), randomVector2.end());
        randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
        //print(randomVector1.begin(), randomVector1.end());
        QVERIFY(!std::is_sorted(randomVector1.begin(), randomVector1.end()));
        merge(randomVector1, randomVector1.begin(), randomVector1.begin() + v1Length-1);
        QVERIFY(std::is_sorted(randomVector1.begin(), randomVector1.end()));
    }
}

void TestMergeSort::mergeVectorSTLStyleTest()
{
    int testarray[] = {0,3,11,50,3,6,7,49,81};
    std::vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    std::vector<int>::iterator end1 = intVector.begin();
    end1 = end1 + 3;
    merge(intVector.begin(), end1, intVector.end());
    QVERIFY(std::is_sorted(intVector.begin(), intVector.end()));

    for (int i = 0; i < 50; ++i) {  // repeat 5 times
        // creat two sorted std::vectors of length 10, combine them into an array and test merge on it
        const std::size_t randomVectorLength = 10;
        const int maxRandomNumber = 10;
        std::vector<int> randomVector1;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
                        randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
        std::vector<int> randomVector2;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
                        randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
        std::sort(randomVector1.begin(), randomVector1.end());
        std::vector<int>::iterator end1 = randomVector1.end();
        std::sort(randomVector2.begin(), randomVector2.end());
        randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
        //print(randomVector1.begin(), randomVector1.end());
        QVERIFY(!std::is_sorted(randomVector1.begin(), randomVector1.end()));
        merge(randomVector1.begin(), randomVector1.begin() + randomVectorLength -1, randomVector1.end());
        QVERIFY(std::is_sorted(randomVector1.begin(), randomVector1.end()));
    }

    const std::size_t vMin = 100;
    const std::size_t vMax = 200;
    const int maxRandomNumber = 25000;
    for (int i = 0; i < 50; ++i) {
        const std::size_t v1Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t v2Length = vMin+rand()%(vMax-vMin+1);
        const std::size_t aLength = v1Length + v2Length;
        std::vector<int> randomVector1;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
                        v1Length, []() { return rand()%(maxRandomNumber+1); });
        std::vector<int> randomVector2;
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
                        v2Length, []() { return rand()%(maxRandomNumber+1); });
        std::sort(randomVector1.begin(), randomVector1.end());
        std::sort(randomVector2.begin(), randomVector2.end());
        randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
        //print(randomVector1.begin(), randomVector1.end());
        QVERIFY(!std::is_sorted(randomVector1.begin(), randomVector1.end()));
        merge(randomVector1.begin(), randomVector1.begin() + v1Length-1, randomVector1.end());
        QVERIFY(std::is_sorted(randomVector1.begin(), randomVector1.end()));
    }
}

QTEST_MAIN(TestMergeSort)
#include "mergesorttest.moc"

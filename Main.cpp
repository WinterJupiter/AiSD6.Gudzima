#include <vector>
#include <iostream>


using namespace std;

int get_k()
{
    while (true)
    {
        int k = 0;
        cin >> k;
        if ((k == 0) || (k == 224)) cin >> k;
        if ((k == 1) || (k == 2) || (k == 3) || (k == 4)) return k;
        else cout << "Repeat input";
    }
}

vector<int> input(size_t n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }
    return v;
}

struct stats
{
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

void Print(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
}

stats Bubble(std::vector<int>& data) //n^2
{
    stats bubble;
    for (size_t i = 0; i < data.size() - 1; i++)
        for (size_t j = 0; j < data.size() - i - 1; j++)
            if (data[j] > data[j + 1])
            {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                bubble.comparison_count++;
                bubble.copy_count++;
            }
    Print(data);
    return bubble;
}

stats Shaker(std::vector<int>& data) //n^2
{
    stats shaker;
    int beyond = data.size() - 1;
    int left = 0;
    int right = data.size() - 1;
    do {
        for (int i = left; i < right; i++)
            if (data[i] > data[i + 1])
            {
                swap(data[i], data[i + 1]);
                beyond = i;
            }
        right = beyond;
        for (int i = right; i > left; i--)
            if (data[i] < data[i - 1])
            {
                swap(data[i], data[i - 1]);
                beyond = i;
            }
        left = beyond;
    } while (left < right);
    Print(data);
    return shaker;
}

void Heap_Sort(std::vector<int>& data, size_t root, size_t size, stats& h)
{
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;
    size_t largest = root;
    //
    if (largest != root)
    {
        int tmp = data[root];
        data[root] = data[largest];
        data[largest] = tmp;
        h.copy_count += 3;
        Heap_Sort(data, largest, size, h);
    }
}

stats Heap(std::vector<int>& data) //n*log(n)
{
    stats heap;
    int size = int(data.size());
    for (int i = size / 2 - 1; i >= 0; --i)
        Heap_Sort(data, i, size, heap);
    for (int i = size - 1; i > 0; i--)
    {
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        heap.copy_count += 3;
        Heap_Sort(data, 0, i, heap);
    }
    Print(data);
    return heap;
}

int main()
{
    size_t n;
    cout << "Let's work!\nVector size: ";
    cin >> n;
    vector<int> v = input(n);
    vector<int> w = v;
    while (true)
    {
        system("cls");
        cout << "1 - Bubble sort\n2 - Shaker sort\n3 - Heap sort\n4 - Exit\n\n";
        int m = get_k();
        if (m == 1)
        {
            Bubble(w);
            system("pause");
            w = v;
        }
        if (m == 2)
        {
            Shaker(w);
            system("pause");
            w = v;
        }
        if (m == 3)
        {
            Heap(w);
            system("pause");
            w = v;
        }
        if (m == 4) break;
    }
    return 0;
}

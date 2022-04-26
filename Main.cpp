#include <vector>
#include <iostream>


using namespace std;

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

stats Bubble(std::vector<int>& data)
{

}

stats Shaker(std::vector<int>& data)
{
    
}

stats Heap(std::vector<int>& data)
{
    
}

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


int main()
{
    cout << "Input vector: ";

    while (true)
    {
        system("cls");
        cout << "1 - Bubble sort\n2 - Shaker sort\n3 - Heap sort\n4 - Exit\n\n";
        int m = get_k();
        if (m == 1)
        {

        }
        if (m == 2)
        {

        }
        if (m == 3)
        {

        }
        if (m == 4) break;
    }
    return 0;
}
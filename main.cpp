//Добавлять элемент в конец. ok
//Выдавать текущее количество элементов.
//Выдавать элемент по индексу. ok
//Изменять элемент по индексу. ok
//Удалять элемент по индексу. ok
//Вставлять элемент по индексу.
#include <iostream>

class DinamicArr
{
private:
    int m_index = 0;
    int m_n = 0;
    int* m_a = NULL;

public:

    DinamicArr(int n)
    {
        m_n = n;
    }
    void Create (int n, int* a)
    {
        m_a = new int[n];
        for (int i = 0; i < m_n; i++)
            std::cin>>m_a[i];
    };

    void InsertElement() //Вставить элемент по индексу
    {
        int insin, insel;
        int* masins = new int[m_n++];
        std::cout<<"Введите индекс, куда хотите вставить элемент ";
        std::cin>>insin;
        std::cout<<"Введите элемент, который хотите вставить ";
        std::cin>>insel;
        for (int i = 0; i < insin; i++)
            masins[i] = m_a[i];
        masins[insin+1] = m_a[insin];
        masins[insin] = insel;
        for (int i = insin+1; i < m_n;i++)
            masins[i+1] = m_a[i];

        delete [] m_a;
        m_a = masins;
    };

    void DeleteElement()//Удаление элемента по индексу
    {
        int delin;
        int* masiv = new int[m_n --];
        std::cout<<"Введите индекс элемента, который хотите удалить ";
        std::cin>>delin;
        for(int i = 0;  i < delin; i++)
            masiv[i] = m_a[i];
        for(int j = delin++; j<m_n;j++)
            masiv[j]= m_a[j+1];
        delete [] m_a;
        m_a = masiv;
    };

    void ChangeElement() //Изменение элемента по индексу
    {
        int chin, chel;
        std::cout<<"Введите индекс элемента, который хотите изменить ";
        std::cin>>chin;
        for (int i = 0; i < m_n; i++)
            if (i == chin)
            {
                std::cout<<"Введите элемент: ";
                std::cin>>chel;
                m_a[i] = chel;
            }
    }

    void AddElement(int el) //Добавление элемента
    {
        int *mas = new int[m_n++];
        for (int i = 0; i < m_n; i++)
            mas[i] = m_a[i];
        m_n --;
        std::cout<<"Введите элемент, который хотите добавить ";
        std::cin >> el;
        mas[m_n] = el;
        delete[] m_a;
        m_a = mas;
        m_n ++;
    }
    void Print()
    {
        std::cout<<"Вывод массива: ";
        for (int i = 0; i < m_n; i++)
            std::cout<<m_a[i]<<" ";
        std::cout<<std::endl;
    }
    int OutputIndex() //выводит элемент по индексу
    {
        std::cout<<"Какой элемент по индексу хотите вывести? ";
        std::cin>>m_index;
        for(int i = 0; i < m_n; i++)
            if (i == m_index)
            {
                std::cout<<"Элемент под индексом "<<m_index<<" это - ";
                std::cout<<m_a[i];
            }
        std::cout<<std::endl;
    }
    int CountEl() //выводит текущее кол-во элементов
    {
        std::cout<<"Текущее кол-во элементов: ";
        return m_n;
    }

    ~DinamicArr()
    {
        delete [] m_a;
    }
};

int main()
{
    int* a;
    int n;
    int el;
    std::cout<<"Задайте количество чисел, которое хотите ввести: ";
    std::cin>>n;
    DinamicArr arr(n);
    std::cout<<"Введите числа: ";
    arr.Create(n, a);
    arr.AddElement(el);
    arr.Print();
    arr.OutputIndex();
    std::cout<<arr.CountEl()<<std::endl;
    arr.ChangeElement();
    arr.Print();
    arr.DeleteElement();
    arr.Print();
    arr.InsertElement();
    arr.Print();
    return 0;
}
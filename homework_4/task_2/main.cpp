#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

    int GetValue(int node)
    {
        auto current = m_head;
        if (node > 0)
        {
            for (int i = 0; i < node; ++i)
            {
                current = current->next;
            }
            return current->value;
        }
        else
        {
            return 0;
        }
    }

    void printList()
    {
        auto current = m_head;
        while (current != m_tail)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "size = " << m_size << std::endl;
        std::cout << std::endl;
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("test List::PushBack", "[PushBack]") // Тестирование функции PushBack
{
    List list1;
    list1.PushBack(5);
    CHECK(list1.GetValue(1) == 5); // Первый узел должен содержать 5
    list1.PushBack(10);
    CHECK(list1.GetValue(2) == 10); // Второй узел должен содержать 10
    CHECK(list1.GetValue(1) == 5);// Первый узел должен содержать 5
}

TEST_CASE("test List::PushFront", "[PushFront]") // Тестирование функции PushFront
{
    List list1;
    list1.PushFront(5);
    CHECK(list1.GetValue(1) == 5); // Первый узел должен содержать 5
    list1.PushFront(10);
    CHECK(list1.GetValue(1) == 10); // Первый узел должен содержать 10
    CHECK(list1.GetValue(2) == 5); // Второй узел должен содержать 5
}

TEST_CASE("test List::PopBack", "[PopBack]") // Тестирование функции PopBack
{

}

TEST_CASE("test List::PopFront", "[PopBack]") // Тестирование функции PopFront
{

}

int main()
{
    return Catch::Session().run();
}
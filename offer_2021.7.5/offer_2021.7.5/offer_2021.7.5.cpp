#include <iostream>
#include <vector>

using namespace std;

//把一个字符串转换成整数
int StrToInt(const char* str) {
  int res = 0;
  //str==nullptr
  if (str == nullptr) {
    return res;
  }
  //str前面含有""
  while (*str == ' ') {
    str++;
  }
  //str第一位的符号"+" "-"
  bool Is_Negative = false;
  if (*str == '-' || *str=='+') {
    Is_Negative = *str == '-' ? true : false;
    str++;
  }
  //溢出
  while (*str != 0) {
    if (*str >= '0' && *str <= '9') {
      if (res > INT_MAX / 10 || res == INT_MAX / 10 && (*str - '0' > 7)) { //即将溢出
        return Is_Negative ? INT_MIN : INT_MAX;
      }
      res = res * 10 + ((*str) - '0');
      str++;
    } else {
      break;
    }
  }
  return Is_Negative ? res * -1 : res;
}

//寻找链表的倒数第K个节点
struct ListNode {
  struct ListNode* next;
  int val;
  ListNode() {
    next = nullptr;
    val = 0;
  }
};
ListNode* FindKNode(ListNode* head,int k) {
  //head==nullptr
  if (head == nullptr) {
    return nullptr;
  }
  //k==0
  if (k == 0) {
    return nullptr;
  }
  //k<ListNode
  ListNode* fast = head;
  ListNode* slow = head;
  while (k--) {
    if (fast == nullptr) {
      return nullptr;
    }
    fast = fast->next;
  }
  while (fast != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

//剑指offer-string类的拷贝构造和operator=
class MyString {
public:
  typedef char* iterator;
  MyString(const char* str)
    :size_(strlen(str)) {
    str_ = new char[size_ + 1];
    strcpy(str_, str);
  }
  ~MyString() {
    delete[]str_;
    str_ = nullptr;
    size_ = 0;
  }
  MyString(const MyString& str) {
    MyString tmp_str(str.str_);
    swap(str_, tmp_str.str_);
  }
  MyString& operator=(const MyString& str) {
    if (*this != str) {
      MyString tmp(str);
      swap(str_, tmp.str_);
    }
    return *this;
  }
  bool operator==(const MyString& s)
  {
    return strcmp(str_, s.str_) == 0;
  }
  bool operator!=(const MyString& s)
  {
    return !(*this == s);
  }
private:
  char* str_;
  size_t size_;
};

int main()
{
  cout << StrToInt("   5252351651651515461451651561sdaf15");
  return 0;
}



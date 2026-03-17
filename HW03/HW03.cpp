#include <iostream>
#include <string>
using namespace std;

template <typename T>

class Inventory
{
private:
	T* pItem_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10) : size_(0)
	{
		if (capacity < 1)
		{
			cout << "용량이 1 이하이므로 최소 용량 1으로 설정합니다" << endl << endl;
			capacity_ = 1;
		}
		else
		{
			capacity_ = capacity;
			cout << "인벤토리의 최대 칸을 " << capacity_ << " (으)로 설정합니다." << endl << endl;
		
		}
		
		pItem_ = new T[capacity_];
	}
	
	~Inventory() {
		delete[] pItem_;   
		pItem_ = nullptr;  
	}

	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			cout << "인벤토리가 가득 찼습니다." << endl << endl;
			return;
		}

		pItem_[size_++] = item;
	}

	void RemoveLastItem()
	{
		if (size_ == 0)
		{
			cout << "제거할 아이템이 없습니다." << endl << endl;
			return;
		}

		for (int i = 0; i < size_ - 1; i++)
		{
			pItem_[i] = pItem_[i + 1];
		}

		size_--;

	}

	void PrintAllItems() const
	{
		cout << "인벤토리 목록" << endl;

		if (size_ == 0)
		{
			cout << "아이템이 들어 있지 않음" << endl << endl;
			return;
		}

		for (int i = 0; i < size_; i++)
		{
			cout << i + 1 << "번 아이템: ";
			pItem_[i].PrintInfo();
		}

	}

	int GetSize() const { return size_; }

	int GetCapacity() const{ return capacity_; }

};

class Item
{
private:
	string name;
	int price;

public:
	Item() : name(""), price(0) {}

	Item(string n, int p) : name (n), price(p){}

	void PrintInfo() const 
	{
		cout << "[이름: " << name << ", 가격: " << price << "골드]" << endl;

	}

};

int main()
{
	int maxInven;
	int Choice;
	string itemName;
	int itemPrice;

	cout << "인벤토리의 최대 칸 수를 입력하시오: ";
	cin >> maxInven;

	Inventory<Item>inventory(maxInven);
	
	while(true)
	{
		cout << "---메뉴---" << endl;
		cout << "1. 아이템 추가 2. 아이템 제거 3.아이템 보기 " << endl;
		cout << "4. 인벤토리 현재 용량 보기 5.인벤토리 최대 용량 보기 6. 남은 인벤토리 용량 보기 0.프로그램 종료" << endl;
		cin >> Choice;

		switch (Choice)
		{
			case 0:
				return 0;
	
 			case 1: 
				cout << "아이템 이름: ";
				cin >> itemName;
	
				cout << "아이템 가격: ";
				cin >> itemPrice;

				inventory.AddItem(Item(itemName, itemPrice));
				cout << itemName << "이(가) 추가되었습니다!" << endl;
				cout << itemName << "의 가격은 " << itemPrice << "입니다." << endl << endl;
				break;

			case 2:
				inventory.RemoveLastItem();
				cout << "인벤토리에서 가장 오래된 아이템이 삭제되었습니다." << endl << endl;
				break;
				
			case 3:
				inventory.PrintAllItems();
				break;

			case 4:
				cout << "인벤토리에 현재 값은 " << inventory.GetSize() << "칸 입니다" << endl << endl;
				break;

			case 5:	
				cout << "인벤토리에 최대값은 " << inventory.GetCapacity() << "칸 입니다" << endl << endl;
				break;

			case 6:
				cout << "현재 인벤토리에 남은 값은 " << inventory.GetCapacity() - inventory.GetSize() << "칸 입니다" << endl << endl;
				break;

			default: cout << "잘못된 입력입니다." << endl;
		}

	}

	return 0;
}
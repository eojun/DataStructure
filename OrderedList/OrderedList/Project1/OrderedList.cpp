
#include <stdio.h>
#include "OrderedList.h"


template < typename DataType, typename KeyType >
OrderedList<DataType, KeyType>::OrderedList(int maxNumber): List<DataType>(maxNumber)
{}


template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::insert(const DataType &newDataItem)
{

	if (size == 0)
	{
		dataItems[++cursor] = newDataItem;
		size++;
		cursor = size - 1;

		cout << "first if a " << "size: " << size <<endl;
	}

	else if (size == 1)
	{
		size++;
		if (newDataItem.getKey() >= dataItems[0].getKey())
			dataItems[1] = newDataItem;
		else // newDataItem.getKey() <= dataItems[0].getKey()
		{
			dataItems[1] = dataItems[0];
			dataItems[0] = newDataItem;
		}
	}

	else if (size < maxSize)
	{
		size++;		
		int index;

		int low = 0;           // Low index of current search range
		int	high = size - 1;   // High index of current search range
		int mid;

		while (low <= high)
		{
			mid = (low + high) / 2;                  //중간지점계산

			if (searchKey >= dataItems[mid].getKey() && searchKey <= dataItems[mid + 1].getKey())
			{
				index = mid;
				break;
			}

			else if (searchKey < dataItems[mid].getKey())
				high = mid - 1;
			else if (searchKey > dataItems[mid].getKey())
				low = mid + 1;

		}

		//binarySearch(newDataItem.getKey(), index);
		cout << "test"<<index;
		for (int i = index; i < size; i++)
		{
			dataItems[i + 1] = dataItems[i];
		}
		dataItems[index] = newDataItem;
		cursor = index;
		

	}
	else if (size >= maxSize)
		cout << "List is full 2" << endl;
}

template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::replace(const DataType &newDataItem)
{
	if (size != 0)
		dataItems[cursor] = newDataItem;
}

template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::retrieve (const KeyType& searchKey, DataType &searchDataItem)
{
	int index;
	if (binarySearch(searchKey, index))
	{
		cursor = index;
		searchDataItem = dataItems[index];
		return true;
	}

	return false;
}

template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::showStructure()
{
	if (size == 0)
		cout << "Empty list" << endl;
	else {
		for (int i = 0; i < size; i++) {
			cout << dataItems[i].getKey() << " , ";
		}
		cout << endl;
		cout << "Current cursor pointed: " << cursor << endl;
	}
}

template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::binarySearch(KeyType searchKey, int &index)
{

	int low = 0;           // Low index of current search range
	int	high = size - 1;   // High index of current search range
	int mid;
	bool result;         // return result

	while (low <= high)
	{
		mid = (low + high) / 2;                  //중간지점계산

		if (searchKey >= dataItems[mid].getKey() && searchKey <= dataItems[mid+1].getKey() )
		{
			index = mid;
			result = true;
			break;
		}

		else if (searchKey < dataItems[mid].getKey())
			high = mid - 1;
		else if (searchKey > dataItems[mid].getKey())
			low = mid + 1;

		result = false;
	}


	return result;
}

template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::merge(const OrderedList<DataType, KeyType> &other)
{

}


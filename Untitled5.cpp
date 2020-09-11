//请你定义一个顺序表，可以对顺序表进行如下操作：
//在某个元素之前插入一些元素
//删除某个位置的元素
//查找某元素
//获取某个位置的元素
//遍历输出所有元素
//键盘输入一些命令，可以执行上述操作。本题中，顺序表元素为整数，顺序表的第一个元素位置为1，顺序表的最大长度为20
#include<iostream>
using namespace std;
const int MaxSize = 20;
template <typename DataType>

class SeqList{
	public:
		SeqList();
		SeqList(DataType a[],int n);
		~SeqList();
		int Length();
		DataType Get(int i);
		int Locate(DataType x);
		void Insert(int i,DataType x);
		DataType Delete(int i);
		void PrintList();
	private:
		int length;
		DataType data[MaxSize];
		
};
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[],int n){
	if(n>MaxSize) throw "参数非法";
	for(int i = 0 ; i < n ; i++){
		data[i] = a[i];
	} 
	length = n;
}
template <typename DataType>
void SeqList<DataType>:: PrintList(){
	for(int i = 0 ; i < length ; i++){
		cout<<data[i]<<"/t";
		cout<<endl;
	}
}
template <typename DataType>
DataType SeqList<DataType>::Get(int i){
	if(i < 1||i> length) throw "查找位置非法";
	else return data[i-1];
}
template <typename DataType>
int SeqList<DataType>::Locate(DataType x){
	for(int i = 0 ; i < length ; i++){
		if(data[i] == x) return i+1;
		return 0;
	}
}
template <typename DataType>
void SeqList<DataType>::Insert(int i,DataType x){
	if(length == MaxSize) throw"上溢";
	if(i<1||i>length+1) throw"插入位置错误";
	for(int j = length ; j>= i ; j--){
		data[j] = data[j-1];
		data[j-1] = x;
		length++;
	} 
}
template <typename DataType>
DataType SeqList<DataType>::Delete(int i){
	DataType x;
	if(length == 0) throw"下溢";
	if(i<1||i>length+1) throw"删除位置错误";
	x = data[i-1];
	for(int j = 1;j<length;j++){
		data[j-1] = data[j];
	}
	length--;
	return x;
}
int main(int argc , char** argv){
	char c;
	int n = 5;
	int a[n] ={1,2,3,4,5}; 
	//SeqList<int> seq = new SeqList<int>(a,n);
	while(1){
		switch(c){
			case 'S':
				Get(int i);
			case 'G':
				Locate(DataType x);
			case 'D':
				Delete(int i);
			case 'V':
				PrintList();
			case 'E':
				exit(1);
			default:
				printf("输入出错 ");
				break; 
				
		}
	}
	return 0;
} 

#include <iostream>
using namespace std;

# define MAX_ELEMENTS 200

int heap[MAX_ELEMENTS];
int num; /*heap總數*/

void insert(int val){ /*heap加入數值value*/
	int i;
	
	if (num >= MAX_ELEMENTS)
	   cout << "Heap滿了 " << endl;
	   
    i =++num;       /*先將num+1以後傳給i 讓樹根為heap[1]*/   

    /* 確定樹有值 且 要加入的樹大於他的parnt*/
    while((i != 1) && (val > heap[i/2]))
    {
    	heap[i] = heap[i/2];  /*parent的值與加入的值的空位交換*/
    	i/=2;                 /*i變為parent的位置*/
	}
	
	/*樹為空 且 要加入的數大於他的parent，直接放入 */
	heap[i] = val;
}

void deleteMax(){
	int parent, child, temp;
	
	if (num == 0)
	{
		cout << "Heap是空的 " << endl;
		return; 
	}
	
	temp = heap[num--];      /*令temp為heap的最後一個數*/
	
	parent = 1;
	child = 2;
	cout << "刪除 " << heap[parent] << "完成，堆積中尚有" << num << "個數值" << endl;
	
	
	
	while (heap[child] >= temp) /*如果被刪的數的child比temp大*/
	{   /*~~child中較大者交換~~*/
		/* 不是最後一數 且 左子樹>右子樹*/
		if((heap[child] > temp) && (heap[child]) > heap[child+1])
		{
		heap[parent] = heap[child]; /*左子樹的值放到parent指向的位子*/
		parent = child;   /*左子樹的值變成parent*/
		child *= 2;       /*新的child下移動*/
	   }
	   /* 左子樹<右子樹的情況*/
	   else if((heap[child+1] > temp) && (heap[child]) < heap[child+1])
	   {
	   	heap[parent] = heap[child+1]; /*右子樹的值放到parent指向的位子*/
		parent = child+1;   /*原本的右子樹的值變成parent*/
		child *= 2;       /*新的child下移動*/
	   }
		/*如果temp較child大則跳出，符合準則*/ 
		if ((temp >= heap[child])&&(temp >= heap[child+1])) 
		break;

	}
	
	heap[parent] = temp;   /*最後一個數為樹的最大值，直接放到樹根*/
	
}

void printHeap(){ /*列出heap的部分*/
	int i;
	
	if (num == 0)
	{
		cout << "Heap是空的 " << endl;
		return; 
	}
	
	for (i = 1; i <= num; i++)  
	   cout << "欄位 " << i <<"為" << heap[i] << endl;
	    
}
 
int main(){
	
	int order; /*指令*/ 
	int val;
	num = 0;

	do
	{
		system("cls");  /*清空畫面*/
		
		cout << "A program of MaxHeap." << endl;
		cout << "(1)Insert a Value." << endl;
		cout << "(2)Delete MaxValue." << endl;
		cout << "(3)Print out the Heap." << endl;
		cout << "(4)Exit." << endl;
		cout << "--------------------------------" << endl;
		
		cout << "輸入要執行的選項:" ;
		cin >> order; /*指令數字輸入→引出的動作*/ 
		cout << endl;
		
		switch (order)
		{
			case 1: /*if輸入為1，加入值*/
				cout << "輸入0以終止" << endl;
				
				do{
					cout << "輸入新增的值: ";
					cin >> val;
					
					if(val!=0) /*輸入非0，則繼續加入*/
					    insert(val);
					    
					}while(val!=0);
					
					system("PAUSE");
					break;
					
				case 2:
					
					deleteMax();  /*if輸入為2，執行deleteMax*/
					cout << endl;
					system("PAUSE");
					break;
					
				case 3:
					
					printHeap(); /*if輸入為3，印出printHeap*/
					cout << endl;
					system("PAUSE");
					break;
					
				case 4: /*if輸入為4，跳出程式*/
					break;
					
				default:
					cout << " 請輸入1-4的數字 " << endl; /*if輸入為1-4以外數字，顯示*/ 
					system("PAUSE");
					break; 
			} 
		}while (order != 4);
	
	return 0;
	}


	



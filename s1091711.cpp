#include <iostream>
using namespace std;

# define MAX_ELEMENTS 200

int heap[MAX_ELEMENTS];
int num; /*heap�`��*/

void insert(int val){ /*heap�[�J�ƭ�value*/
	int i;
	
	if (num >= MAX_ELEMENTS)
	   cout << "Heap���F " << endl;
	   
    i =++num;       /*���Nnum+1�H��ǵ�i ����ڬ�heap[1]*/   

    /* �T�w�𦳭� �B �n�[�J����j��L��parnt*/
    while((i != 1) && (val > heap[i/2]))
    {
    	heap[i] = heap[i/2];  /*parent���ȻP�[�J���Ȫ��Ŧ�洫*/
    	i/=2;                 /*i�ܬ�parent����m*/
	}
	
	/*�𬰪� �B �n�[�J���Ƥj��L��parent�A������J */
	heap[i] = val;
}

void deleteMax(){
	int parent, child, temp;
	
	if (num == 0)
	{
		cout << "Heap�O�Ū� " << endl;
		return; 
	}
	
	temp = heap[num--];      /*�Otemp��heap���̫�@�Ӽ�*/
	
	parent = 1;
	child = 2;
	cout << "�R�� " << heap[parent] << "�����A��n���|��" << num << "�Ӽƭ�" << endl;
	
	
	
	while (heap[child] >= temp) /*�p�G�Q�R���ƪ�child��temp�j*/
	{   /*~~child�����j�̥洫~~*/
		/* ���O�̫�@�� �B ���l��>�k�l��*/
		if((heap[child] > temp) && (heap[child]) > heap[child+1])
		{
		heap[parent] = heap[child]; /*���l�𪺭ȩ��parent���V����l*/
		parent = child;   /*���l�𪺭��ܦ�parent*/
		child *= 2;       /*�s��child�U����*/
	   }
	   /* ���l��<�k�l�𪺱��p*/
	   else if((heap[child+1] > temp) && (heap[child]) < heap[child+1])
	   {
	   	heap[parent] = heap[child+1]; /*�k�l�𪺭ȩ��parent���V����l*/
		parent = child+1;   /*�쥻���k�l�𪺭��ܦ�parent*/
		child *= 2;       /*�s��child�U����*/
	   }
		/*�p�Gtemp��child�j�h���X�A�ŦX�ǫh*/ 
		if ((temp >= heap[child])&&(temp >= heap[child+1])) 
		break;

	}
	
	heap[parent] = temp;   /*�̫�@�ӼƬ��𪺳̤j�ȡA���������*/
	
}

void printHeap(){ /*�C�Xheap������*/
	int i;
	
	if (num == 0)
	{
		cout << "Heap�O�Ū� " << endl;
		return; 
	}
	
	for (i = 1; i <= num; i++)  
	   cout << "��� " << i <<"��" << heap[i] << endl;
	    
}
 
int main(){
	
	int order; /*���O*/ 
	int val;
	num = 0;

	do
	{
		system("cls");  /*�M�ŵe��*/
		
		cout << "A program of MaxHeap." << endl;
		cout << "(1)Insert a Value." << endl;
		cout << "(2)Delete MaxValue." << endl;
		cout << "(3)Print out the Heap." << endl;
		cout << "(4)Exit." << endl;
		cout << "--------------------------------" << endl;
		
		cout << "��J�n���檺�ﶵ:" ;
		cin >> order; /*���O�Ʀr��J���ޥX���ʧ@*/ 
		cout << endl;
		
		switch (order)
		{
			case 1: /*if��J��1�A�[�J��*/
				cout << "��J0�H�פ�" << endl;
				
				do{
					cout << "��J�s�W����: ";
					cin >> val;
					
					if(val!=0) /*��J�D0�A�h�~��[�J*/
					    insert(val);
					    
					}while(val!=0);
					
					system("PAUSE");
					break;
					
				case 2:
					
					deleteMax();  /*if��J��2�A����deleteMax*/
					cout << endl;
					system("PAUSE");
					break;
					
				case 3:
					
					printHeap(); /*if��J��3�A�L�XprintHeap*/
					cout << endl;
					system("PAUSE");
					break;
					
				case 4: /*if��J��4�A���X�{��*/
					break;
					
				default:
					cout << " �п�J1-4���Ʀr " << endl; /*if��J��1-4�H�~�Ʀr�A���*/ 
					system("PAUSE");
					break; 
			} 
		}while (order != 4);
	
	return 0;
	}


	



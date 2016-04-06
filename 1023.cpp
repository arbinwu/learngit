#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
void mystrrev(char *str){
	char tmp[25];
	strcpy(tmp,str);
	int len=strlen(str);
	for(int j=0;tmp[j]!='\0';j++){
		len--;
		str[len]=tmp[j];
	}
}
int main(){
	char in[25];
	while(scanf("%s",in)!=EOF){
		char db[25];
		int len1=strlen(in);
		int num1[10]={0};
		int num2[10]={0};
		for(int i=0;i<len1;i++){
			int d=in[i]-'0';
			num1[d]++;
		}
		mystrrev(in);
		int next=0;
		int p;
		for(p=0;in[p]!='\0';p++){
			db[p]=((in[p]-'0')*2+next)%10+'0';
			next=((in[p]-'0')*2)/10;
		}
		if(next!=0){
			db[p]='0'+next;
			db[p+1]='\0';
		}else{
			db[p]='\0';
		}
		int len2=strlen(db);
		for(int i=0;i<len2;i++){
			int d=db[i]-'0';
			num2[d]++;
		}
		bool flag=true;
		for(int i=0;i<10;i++){
			if(num1[i]!=num2[i]){
				flag=false;
			}
		}
		flag==true? printf("Yes\n"):printf("No\n");
	//	cout<<db<<endl;
			for(int i=len2-1;i>=0;i--){
				printf("%c",db[i]);
			}
			printf("\n");
		
	}
} 

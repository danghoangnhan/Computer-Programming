#include <iostream>

using namespace std;

template <typename T>
 void sorting(T a[],int length){
    for(int i=1;i<length;i++){
        for(int j=0;j<length-i;j++){
            if(a[j]>a[j+1]){
               T tempt = a[j];
               a[j]=a[j+1];
               a[j+1]=tempt;
               }
        }
    }



}

int main()
{
  while(1){

        int length,type;
        cin>>length>>type;
        if(length==0)
            break;

  switch(type){
      case 0:{
            char a[1000];
          for(int i=0;i<length;i++)
            cin>>a[i];
          sorting(a,length);
           for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
          break;

      }
      case 1:{
          int a[1000];
          for(int i=0;i<length;i++)
            cin>>a[i];
           sorting(a,length);
            for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
           break;
      }
      default:{
          double a[1000];
          for(int i=0;i<length;i++)
            cin>>a[i];
           sorting(a,length);
            for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
           break;
      }

  }
  }
}

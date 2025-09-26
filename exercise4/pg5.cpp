# include <iostream>
using namespace std; 

class Matrix{
    int **arr;
    int m;
    int n;
    public:
        Matrix();
        int & rows(){
            return m;
        }
        int & cols(){
            return n;
        }
        void show_data();
        int & operator ()(int i,int j);
};
Matrix :: Matrix(){
    cout<<"Enter m and n: ";
    cin>>m>>n;
    arr=new int *[m];
    for(int i=0;i<m;i++){
        arr[i]=new int [n];
    }
    cout<<"Enter array \n";
    for(int i=0;i<m;i++){
        cout<<"Enter row "<<i<<endl;
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
}

void Matrix::show_data(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int & Matrix::operator()(int i,int j){
    if((i<0 || i>m) || (j<0 || j>n) ){
        cout<<"Invalid index";
        exit(1);
    }
    return arr[i][j];
}

int main(){
    Matrix M;
    M.show_data();
    cout<<"Modified Matrix is :\n";
    for(int i=0;i<M.rows();i++){
        for(int j=0;j<M.cols();j++){
            cout<<M(i,j)*2<<" ";
        }
        cout<<endl;
    }
}

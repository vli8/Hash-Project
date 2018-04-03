//Victor Li
//Algorithms
//main file for Hash lab

#include"Point.h"
//generating random points
int generateRandomPoints(){
        return rand()%40+0;//making sure to have point 0 to 40
}

int main(){

        int num;
        cout << "How many points do you want to generate? " <<endl;
        cin >> num;//user's input to generate random points

        int x, y;//creating object
        Point p(x,y);

        unordered_set<Point, Hasher> set1;

        srand(time(0));//random generator

        for(int i=0; i<num; i++){//generating points x, y depending on users input
                x = generateRandomPoints();
                y= generateRandomPoints();

                p.setXandY(x,y);

                set1.insert(p);//inserting each pair coordinates in set1
        }

        for (Point p : set1){//iterating through each object of the set
                cout << p << endl;
        }

        for(int row=0;row<41;row++){
                for(int col=0;col<41;col++){
                        if(set1.find(Point(row,col)) == set1.end()){//if it arrives to the end of the set, it means the coordinates are not here
                                cout << " ";
                        }
                        else
                                cout << "* ";
                }
                cout << endl;
        }
}


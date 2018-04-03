#include <iostream>
#include <functional>
#include<unordered_set>
#include<ctime>
using namespace std;

//Class Point for coodinates and operators overload
class Point{
	//overloading the cout operator 
	friend	ostream & operator<<(ostream & out, const Point & p){
		out <<"("<<p.x<<","<<p.y<<")";
		return out;
	}
	//overloading the checking operator 
	friend bool operator==(const Point & lhs, const Point & rhs){
		return (lhs.x==rhs.x && lhs.y==rhs.y);
	}

	private:
		int x,y;//coordinates
	public:
		Point(int xv=0,int yv=0){//constructor
			x=xv;
			y=yv;
		}
		int getX() const{//get method
			return x;
		}

		int getY() const{//get method
			return y;
		}
		int getSum() const{
			return x+y;
		}
		void setXandY(int x, int y){//set method
			this->x=x;
			this->y=y;
		}

};

//Hashing coordinate X and Y
struct Hasher{
        // overload operator () to implement a hash function on Point object
        //  can be called as follows: Hasher() (Point(11,14))
        //                                         ^^ refer to operator that is defined here of HasherByY class
        // demonstrated in main()
        size_t operator()(const Point & obj) const{
                return hash<int>()(obj.getSum());
                //Note: hash is a template class defined in C++ STL in which the operator() is overloaded
                //Here we call operator() of hash class, passing obj.GetName() as parameter.
                //basically, this will use system provided hash function to hash a string into an unsigned int
  }
};
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

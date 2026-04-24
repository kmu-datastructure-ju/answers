typedef struct
{
	char name[50];
	int stuNum;
	int score;
}Student;

void rFile(int n, Student* arr);
void wStuNum(int n, Student* arr);
void wScore(int n, Student* arr);
int maxi(int n, Student* arr);
int mini(int n, Student* arr);
float ave(int n, Student* arr);
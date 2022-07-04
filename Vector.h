#include <string>
using namespace std;

template <class T>
class Vector
{
	T* array;
	int capacity;
	int current;
public:
	Vector()
	{
		capacity = 10;
		array = new T[capacity];
		for (register short i = 0; i < capacity; ++i)
		{
			array[i] = '\0';
		}
		current = 0;
	}
	void push_back(T data)
	{
		if (current == capacity)
		{
			T* new_array = new T[capacity + 10];
			for (register short i = 0; i < capacity; i++)
			{
				new_array[i] = array[i];
			}
			//delete [] array;
			capacity += 10;
			array = new_array;
		}
		array[current] = data;
		++current;
	}
	bool isEmpty()
	{
		if (current == 0)
		{
			return true;
		}
		return false;
	}
	void pop()
	{
		--current;
	}
	void empty()
	{
		while (current != 0)
		{
			pop();
		}
	}
	int size()
	{
		return current;
	}
	int Size()
	{
		return current;
	}
	T at(int index)
	{
		if (index < current)
		{
			return array[index];
		}
		return 0;
	}
	void set(int index, T data)
	{
		array[index] = data;
	}
	int getCurrent()
	{
		return current;
	}
	int getCapacity()
	{
		return capacity;
	}
	void setCurrent(int i)
	{
		current = i;
	}
	void setCapacity(int i)
	{
		capacity = i;
	}
	Vector& operator = (Vector& rhs)
	{
		this->current = rhs.getCurrent();
		this->capacity = rhs.getCapacity();
		this->array = new T[rhs.getCapacity()];
		for (register short i = 0; i < rhs.getCurrent(); ++i)
		{
			this->array[i] = rhs.at(i);
		}
		return *this;
	}
	int find(T word)
	{
		for (register short i = 0; i < current; ++i)
		{
			if (word == array[i])
			{
				return i;
			}
		}
		return -1;
	}
	T& operator [](string data)
	{
		for (register short i = 0; i < size(); ++i)
		{
			if (data == array[i])
			{
				return array[i];
			}
		}
	}
};
void dateAddition(int& d, int& m, int& y, int x)//Add number of days from given date
{
	bool leapYear = false;
	if (y % 4 == 0 || y % 400 == 0 && y % 100 != 0)
	{
		leapYear = true;
	}

	if (m <= 7 && m % 2 != 0)
	{
		if (d + x > 31)
		{
			m++;
			d = (d + x) - 31;
		}
		else
		{
			d += x;
		}
	}
	else if (m == 2)
	{
		if (leapYear)
		{
			if (d + x > 29)
			{
				m++;
				d = (d + x) - 29;
			}
			else
			{
				d += x;
			}
		}
		else
		{
			if (d + x > 28)
			{
				m++;
				d = (d + x) - 28;
			}
			else
			{
				d += x;
			}
		}
	}
	else if (m <= 7 && m % 2 == 0)
	{
		if (d + x > 30)
		{
			m++;
			d = (d + x) - 30;
		}
		else
		{
			d += x;
		}
	}
	else if (m > 7 && m % 2 == 0)
	{
		if (d + x > 31)
		{
			if (m == 12)
			{
				y++;
				m = 1;
				d = (d + x) - 31;
			}
			else
			{
				m++;
				d = (d + x) - 31;
			}
		}
		else
		{
			d += x;
		}
	}
	else
	{
		if (d + x > 30)
		{
			m++;
			d = (d + x) - 30;
		}
		else
		{
			d += x;
		}
	}
}
void dateSubtraction(int& d, int& m, int& y, int x)//Subtract number of days from given date
{
	bool leapYear = false;
	if (y % 4 == 0 || y % 400 == 0 && y % 100 != 0)
	{
		leapYear = true;
	}

	if (m <= 7 && m % 2 != 0)
	{
		if (d - x <= 0)
		{
			if (m == 1)
			{
				y--;
				m = 12;
				d = (d - x) + 31;
			}
			else if (m == 3)
			{
				if (leapYear)
				{
					m--;
					d = (d - x) + 29;
				}
				else
				{
					m--;
					d = (d - x) + 28;
				}
			}
			else
			{
				m--;
				d = (d - x) + 30;
			}

		}
		else
		{
			d -= x;
		}
	}
	else if (m <= 7 && m % 2 == 0)
	{
		if (d - x <= 0)
		{
			m--;
			d = (d - x) + 31;
		}
		else
		{
			d -= x;
		}
	}
	else if (m > 7 && m % 2 == 0)
	{
		if (d - x <= 0)
		{
			if (m == 8)
			{
				m--;
				d = (d - x) + 31;
			}
			else
			{
				m--;
				d = (d - x) + 30;
			}
		}
		else
		{
			d -= x;
		}
	}
	else
	{
		if (d - x <= 0)
		{
			m--;
			d = (d - x) + 31;
		}
		else
		{
			d -= x;
		}
	}
}
class Time
{
public:
	int fh_time;
	int fm_time;
	int lh_time;
	int lm_time;
	int day;
	int month;
	int year;
	double total_hoursl;
	double total_hoursf;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	Time()
	{
		this->fh_time = 0;
		this->fm_time = 0;
		this->lh_time = 0;
		this->lm_time = 0;
		this->day = 0;
		this->month = 0;
		this->year = 0;
		total_hoursf = 0;
		total_hoursl = 0;
	}
	void set(int day, int month, int year,int fh_time,int fm_time,int lh_time,int lm_time)
	{
		this->fh_time = fh_time;
		this->fm_time = fm_time;
		this->lh_time = lh_time;
		this->lm_time = lm_time;
		this->day = day;
		this->month = month;
		this->year = year;
		total_hoursf = getTotal_hoursf();
		total_hoursl = getTotal_hoursl();
	}
	//This function aren't required ( they were used before but a better way was found than these function)
	void set_total_hoursfb(int hours)
	{
		int check = total_hoursf - hours;
		if (check >= 0)
		{
			total_hoursf -= hours;
		}
	}
	void set_total_hoursff(int hours)
	{
		total_hoursf += hours;
	}
	void display()//Displays the complete date of any flight
	{
		cout << day << "/" << month << "/" << year << " " << fh_time << ":" << fm_time << " " << lh_time << ":" << lm_time << " ";
	}
	const Time& operator=(const Time& obj)
	{
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
		this->lh_time = obj.lh_time;
		this->lm_time = obj.lm_time;
		this->fh_time = obj.fh_time;
		this->fm_time = obj.fm_time;
		this->total_hoursf = obj.total_hoursf;
		this->total_hoursl = obj.total_hoursl;
		return *this;
	}
	//Converting date into Days ( if we go direct from starting date to todays date and calulate tototal no. of values then it will be a very big value
	// we set a base starting , our data needs to be greater than specific value so we get small no. of days and out calc remains easy and not complex
	int countLeapYears(int days,int months,int year)
	{
		int years = year;
		if (months <= 2)
			years--;
		return years / 4 - years / 100 + years / 400;
	}
	double getDifference(int days1, int month1, int year1)//Returns the difference between two dates
	{
		double n1 = year1 * 365 + days1;
		for (int i = 0; i < month1 - 1; i++)
			n1 += monthDays[i];
		n1 += countLeapYears(days1,month1,year1);
		double n2 = year * 365 + day;
		for (int i = 0; i < month - 1; i++)
			n2 += monthDays[i];
		n2 += countLeapYears(day, month, year);
		return (n2 - n1);
	}
	double getTotal_hoursl()//Return the landing time of any flight in hours by converting date and time into hours
	{
		//BASE DATE
		int day1 = 1;
		int month1 = 7;
		int year1 = 2019;
		if (year1 > year)
		{
			exit(-10);
		}
		else if (year1 == year && month1 > month)
		{
			exit(-10);
		}
		else if (year1 == year && month1 == month && day1 > day)
		{
			exit(-10);
		}
		total_hoursl = getDifference(day1, month1, year1) * 24;
		if (lh_time <= fh_time)
		{
			total_hoursl += 24 + lh_time;
		}
		else
		{
			total_hoursl +=lh_time;
		}
		total_hoursl += (lm_time / 60.0);
		return total_hoursl;
	}
	double getTotal_hoursf()//Converts the given date and time into hours and return the flying time of flight into hours 
	{
		//BASE DATE
		int day1 = 1;
		int month1 = 7;
		int year1 = 2019;
		if (year1 > year)
		{
			exit(-10);
		}
		else if (year1 == year && month1 > month)
		{
			exit(-10);
		}
		else if (year1 == year && month1 == month && day1 > day)
		{
			exit(-10);
		}
		total_hoursf = getDifference(day1, month1, year1) * 24;
		total_hoursf += fh_time;
		total_hoursf += (fm_time / 60.0);
		return total_hoursf;
	}
	~Time()
	{

	}
};
class node
{
public:
	//Information
	string destination;
	int dest_index;
	int ticket_price;
	string airline_name;
	Time t;
	//Joining next node
	node* next;
};
class PathSaver
{
public:
	node* source;
	long total_cost = 0;
	//PathSaver* next;
	PathSaver()
	{
		source = NULL;
		//next = NULL;
	}
	int getSourceTime()//Returns the time of starting point
	{
		if (source != NULL)
		{
			return source->t.getTotal_hoursf();
		}
	}
	int getSourceDest()//Returns the name of starting point
	{
		if (source != NULL)
		{
			return source->dest_index;
		}
	}
	void addSource(string dest,int src,int d , int m ,int y)//Adds the starting point to the path
	{
		if (source == NULL)
		{
			source = new node;
			source->destination = dest;
			source->dest_index = src;
			source->ticket_price = 0;
			source->t.set(d, m, y, 0, 0, 0, 0);
			source->airline_name = "";
			source->next = NULL;
			//cout << source->t.getTotal_hoursl() << endl;
			return;
		}
	}
	void setSourceDate(int d, int m, int y)//instead of deleting the whole path and re-adding to check flight on another date we simply change the date of starting point
	{
		source->t.set(d, m, y, 0, 0, 0, 0);
	}

	void newPath(string dest, int dest_i, int price, string airline_n, Time t)//Adds the transit location or destination to Path class
	{
		
		node* tempo = source;
		while (tempo->next != NULL)
		{
			tempo = tempo->next;
		}
		tempo->next = new node;
		tempo->next->destination = dest;
		tempo->next->dest_index = dest_i;
		tempo->next->ticket_price = price;
		tempo->next->t = t;
		tempo->next->airline_name = airline_n;
		tempo->next->next = NULL;

	}
	double last_land_time()//Returns the last land time ( means the last flight landing  in path ) to check whether the next flight fly after or before the last flight in path 
	{
		if (source == NULL  )
		{
			return 0;
		}
		else if (source->next == NULL)
		{
			return source->t.getTotal_hoursf();
		}
		node* tempo = source->next;
		while (tempo->next)
		{
			tempo = tempo->next;
		}
		return tempo->t.getTotal_hoursl();
	}
	void pop()//Removes the point from path ( used for recursion )
	{
		if (!source)
		{
			return;
		}
		else if ( !source->next)
		{
			delete source->next;
			source->next = NULL;
		}
		else
		{
			node* tempo = source;
			while (tempo->next->next != NULL)
			{
				tempo = tempo->next;
			}
			delete tempo->next;
			tempo->next = NULL;
		}
	}
	bool getTransitLocationTime(string transit_location,int stay_time)//return the stayed time at tranit location 
	{
		node* temp = source;
		while (temp->next)
		{
			if (temp->destination == transit_location && ( temp->next->t.getTotal_hoursf() - temp->t.getTotal_hoursl()>= stay_time) )
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void display(Vector<int> &prize )//Display the complete path from starting point to ending point
	{
		//total_cost = 0;
		node* prev = source->next;
		node* temp = source->next;
		cout << "Flight from " << source->destination << " is: " << endl;
		while (temp)
		{
			cout << temp->destination << " ";
			temp->t.display();
			cout << temp->ticket_price << " ";
			cout << temp->airline_name << " ";
			prev = temp;
			temp = temp->next;
			if (temp)
			{
				cout << "to";
			}
			cout << endl;
		}
		cout << "Total cost from " <<  source->destination <<" to "<< prev->destination <<" is " << Calculate_TotalCost(prize) << endl;
		cout << "Total time from " << source->destination << " to " << prev->destination << " is " << TotalTimeTaken() << " hours" << endl;
		cout << endl << endl;
		
	}
	long TotalTimeTaken()//Returns the total time taken to travel from source to destination
	{
		long total_time = 0;
		node* temp = source->next;
		total_time = temp->t.getTotal_hoursf();
		while (temp->next)
		{
			temp = temp->next;
		}
		total_time = temp->t.getTotal_hoursl() - total_time;
		return total_time;
	}
	long Calculate_TotalCost(Vector<int>& prize)//Returns the total cost to reach destination from source
	{
		total_cost = 0;
		node* prev = source->next;
		node* temp = source->next;
		while (temp)
		{
			if (temp->t.getTotal_hoursf() - prev->t.getTotal_hoursl() > 12)
			{
				int g = temp->t.getTotal_hoursf() - prev->t.getTotal_hoursl();
				while (g > 0)
				{
					total_cost += prize.at(prev->dest_index);
					g -= 24;
				}
			}
			total_cost += temp->ticket_price;
			prev = temp;
			temp = temp->next;
		}
		return total_cost;
	}
	long Calculate_TotalTime()//Calculate the time at any given point in path to match it with max travel time and whether flight fly after given date or not
	{
		long total_time = 0;
		node* temp = source;
		total_time = temp->t.getTotal_hoursf();
		while (temp->next)
		{
			temp = temp->next;
		}
		total_time = temp->t.getTotal_hoursl() - total_time;
		return total_time;
	}
	const PathSaver& operator=(PathSaver obj)
	{
		while (obj.source)
		{
			if (this->source == NULL)
			{
				this->addSource(obj.source->destination,obj.source->dest_index, obj.source->t.day, obj.source->t.month, obj.source->t.year);
			}
			else
			{
				this->newPath(obj.source->destination, obj.source->dest_index,
					obj.source->ticket_price, obj.source->airline_name, obj.source->t);
			}		
			obj.source = obj.source->next;
		}
		this->total_cost = obj.total_cost;
		return *this;
	}
	~PathSaver()
	{
		/*node* current = source;
		node* next;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}*/
	}
};
class UltimatePathSaver
{
public:
	PathSaver path;
	UltimatePathSaver* nextPath;
};
class FinalPath
{
public:
	UltimatePathSaver* root;
	FinalPath()
	{
		root = NULL;
	}
	void addPath(PathSaver& p,Vector<int> prize)//Add 1 complete in All path saver class
	{
		if (root == NULL)
		{
			root = new UltimatePathSaver;
			root->path = p;
			root->path.Calculate_TotalCost(prize);
			root->nextPath = NULL;
			return;
		}
		UltimatePathSaver* temp = root;
		//long price_cal = p.Calculate_TotalCost(prize);
		while (temp->nextPath)
		{
			temp = temp->nextPath;
		}
		temp->nextPath = new UltimatePathSaver;
		temp->nextPath->path = p;
		temp->nextPath->path.Calculate_TotalCost(prize);
	}
	void addPathC(PathSaver& p, Vector<int> prize)//Add next path in class on the basis of cost sortation( path is inserted in such a way that linked list remains sorted cost wise
	{
		if (root == NULL)
		{
			root = new UltimatePathSaver;
			root->path = p;
			root->path.Calculate_TotalCost(prize);
			root->nextPath = NULL;
			return;
		}
		UltimatePathSaver* prev = root;
		UltimatePathSaver* temp = root;
		long price_cal = p.Calculate_TotalCost(prize);
		if (price_cal <= prev->path.total_cost)
		{
			UltimatePathSaver *sta = new UltimatePathSaver;
			sta->path = p;
			sta->nextPath = root;
			root = sta;
			//cout << price_cal << endl;
			return;
		}
		while (temp->nextPath && price_cal >= temp->path.Calculate_TotalCost(prize))
		{
			prev = temp;
			temp = temp->nextPath;
		}
		if (temp->nextPath != NULL || price_cal < temp->path.Calculate_TotalCost(prize))
		{
			UltimatePathSaver* sta = new UltimatePathSaver;
			sta->path = p;
			prev->nextPath = sta;
			sta->nextPath = temp;
		}
		else
		{
			temp->nextPath = new UltimatePathSaver;
			temp->nextPath->path = p;
			temp->nextPath->path.Calculate_TotalCost(prize);
		}
	}
	void addPathT(PathSaver& p, Vector<int> prize)//Add next path in class on the basis of travel sortation( path is inserted in such a way that linked list remains sorted travel time wise
	{
		if (root == NULL)
		{
			root = new UltimatePathSaver;
			root->path = p;
			root->path.Calculate_TotalCost(prize);
			root->nextPath = NULL;
			return;
		}
		UltimatePathSaver* prev = root;
		UltimatePathSaver* temp = root;
		long time_cal = p.Calculate_TotalTime();
		if (time_cal <= prev->path.Calculate_TotalTime())
		{
			UltimatePathSaver* sta = new UltimatePathSaver;
			sta->path = p;
			sta->nextPath = root;
			root = sta;
			//cout << time_cal << endl;
			return;
		}
		while (temp->nextPath && time_cal >= temp->path.Calculate_TotalTime())
		{
			prev = temp;
			temp = temp->nextPath;
		}
		if (temp->nextPath != NULL || time_cal < temp->path.Calculate_TotalTime())
		{
			UltimatePathSaver* sta = new UltimatePathSaver;
			sta->path = p;
			prev->nextPath = sta;
			sta->nextPath = temp;
		}
		else
		{
			temp->nextPath = new UltimatePathSaver;
			temp->nextPath->path = p;
			temp->nextPath->path.Calculate_TotalCost(prize);
		}
	}
	void display(Vector<int>prize)
	{
		UltimatePathSaver* temp = root;
		while (temp)
		{
			temp->path.display(prize);
			temp = temp->nextPath;
		}
	}
	~FinalPath()
	{
		UltimatePathSaver* current = root;
		UltimatePathSaver* next;

		while (current != NULL)
		{
			next = current->nextPath;
			delete current;
			current = next;
		}
	}
};

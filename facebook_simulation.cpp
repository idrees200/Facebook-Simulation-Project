#include<iostream>
#include<fstream>
using namespace std;
class Helper
{
public:
	static int StringLenght(char* str)
	{
		int size = 0;
		for (char* temp = str; *temp != '\0'; temp++)//takes base address and return size when string reaches null
			size++;
		return size;
		
	}
	static void StringCopy(char*& dest, char*& src) {
		for (; *src != '\0'; src++, dest++)//takes two strings and copy content of src into dest until its null
		{
			*dest = *src;
		}
		*dest = '\0';

	}


	static char* GetStringFromBuffer(char* str)
	{
		int strLen = StringLenght(str);//takes size of passed string
		char* string = 0;

		if (strLen > 0)//if size is not null
		{
			string = new char[strLen + 1];//allocates memory
			char* tempDest = string;//pointer which points to new string
			char* tempSrc = str;//points to the base address of passed string
			Helper::StringCopy(*&tempDest, *&tempSrc);
			return string;
		}
		else {
			cout << "invalid string" << endl;
		}
	}
	static bool Compare(const char* search, const char* data)
	{
		for (int i = 0; data[i] != NULL; i++)
			if (search[i] != data[i])
				return false;
		return true;
	}
	
};
class facebook;
class user;
class page;
class post;
class activity;
class comment;
class object {
	char* id;
	int postnumber;
	
public:
	object()
	{
		
		id = 0;
		postnumber = 0;
	
	}
	virtual void addtotimeline(post*ptr)//pure virtual
	{	
	}
	virtual void viewnames()
	{
	}
	virtual char* getid()
	{
		return id;

	}
	virtual void viewselectedpost(post* ptr)
	{

	}
	virtual~object()
	{
		delete id;

	}
};

class comment {

	char* postid;
	char* text;
	object* commentby;

public:
	comment() {//constructor
		postid = 0;
		text = 0;
		commentby = new object;

	}
	void ReadDataFromFile1(fstream& fincomments)//just takes postid
	{
		char temp[10];
		fincomments >> temp;
		postid = Helper::GetStringFromBuffer(temp);

	}
	void viewcomments()//prints commments 
	{
	
		cout << "                      ";
		commentby->viewnames();
		cout<< "wrote :" << text << endl;
	}
	void ReadDataFromFile(fstream& fincomments)//file reading for comment text
	{

		char temp[100];
		fincomments.ignore();
		fincomments.getline(temp, 100);
		text = Helper::GetStringFromBuffer(temp);

	}
	void commentbyy(object* cmby)//stores the address of the object which commented(page or user)
	{
		commentby = cmby;

	}
	void setcomment(char temp[])//setter for texts
	{
		text = Helper::GetStringFromBuffer(temp);
	}
	char* getpostid()
	{
		return postid;
	}
	~comment()//destructor
	{
		delete postid;
		delete text;
		delete commentby;
	}
};
class activity {
	int type;
	char* value;
public:
	activity()//constructor
	{
		type = 0;
		value = 0;
	}
	void ReadDataFromFile(fstream& finpost)//reads thee type and valueof activity
	{
		finpost >> type;
		char temp[30];
		finpost.getline(temp, 30);
		value = Helper::GetStringFromBuffer(temp);
	}
	void viewactivity()
	{
		if (type == 1)
		{
			cout << " is feeling excited " << value << endl;
		}
		else if (type == 2)
		{
			cout << " is thinking about " << value << endl;
		}
		else if (type == 3)
		{
			cout << " is making  " << value << endl;
		}
		else if(type==4) {
			cout << " is celebrating " << value << endl;
		}
	}
	~activity()//destructor
	{
		delete value;
	}
};
class Date {
	int day;
	int month;
	int year;
public:
	
	static Date current_date;
	Date()//constructor
	{
		day = month = year = 0;
	}
	void ReadDataFromFile(fstream& finpost)
	{
		finpost >> day;
		finpost >> month;
		finpost >> year;
	}
	static void setdate(int d, int m, int y)//setter for current date
	{
		current_date.day = d;
		current_date.month = m;
		current_date.year = y;
		cout << "Command:                      " << "Set Current Date " << d <<" " <<m <<" "<< y << endl;
		cout << "System Date:                     ";
		cout << "(" << current_date.day << "/" << current_date.month << "/" << current_date.year << ")" << endl;

	}

	void viewdate()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	static Date getcurrentdate()
	{
		return current_date;
	}
	 void setshareddate(int d, int m, int y)//setter for shared date
	{
		day = d;
		month = m;
		year = y;
		
	}

};
Date Date::current_date;//declaring static date
class post {
private:
	char* id;
	char* text;
	Date shareddate;
	comment** comments;
	object* sharedby;
	activity* Activity;
	object** likedby;
	int isActivity;
	int noOflikes;
	int noofcomments;
public:
	post()//constructor
	{
		noofcomments = 0;
		noOflikes = 0;
		isActivity = 0;
		id = 0;
		text = 0;
		sharedby = new object;
		likedby = new object * [10];
		comments = new comment * [10];
		for (int i = 0; i < 10; i++)
		{
			comments[i] = new comment[10];
		}
		Activity = new activity[5];
	}
	void viewdate()//displays date
	{
		cout <<"("<<shareddate.getday() << "/" << shareddate.getmonth() << "/" << shareddate.getyear() <<")"<< endl;
	}
	void ReadDataFromFile(fstream& finpost)
	{

		finpost >> isActivity;
		Activity = new activity;
		char tempbufferid[10];
		finpost >> tempbufferid;
		id = Helper::GetStringFromBuffer(tempbufferid);
		shareddate.ReadDataFromFile(finpost);
		char temp[100];
		finpost.ignore();
		finpost.getline(temp, 100);
		text = Helper::GetStringFromBuffer(temp);
		if (isActivity != 1)
			Activity->ReadDataFromFile(finpost);

	}
	void setsharedby(object* ptr)
	{
		sharedby = ptr;
	}
	
	void setlikedby(object* ptr)
	{
		likedby[noOflikes] = ptr;
		noOflikes++;
	}
	void addcommentstopost(comment* ptr) {//takes a comment pointer and add it to the comments of a post
		comments[noofcomments] = ptr;
		noofcomments++;
	}
	virtual void viewposts()//function for displaying posts
	{
		cout << "--------";
		sharedby->viewnames();
		Activity->viewactivity();
		cout << "\"" << text << "\"" << ".........";
		viewdate();
		for (int i = 0; i < noofcomments; i++)
		{
			comments[i]->viewcomments();
		}


	}
	
	void viewlikedby()

	{
		for (int i = 0; i < noOflikes; i++)
		{
			cout << likedby[i]->getid();
			cout << "-";
			 likedby[i]->viewnames();
			 cout << endl;
		}

	}
	
	object* getsharedby()
	{
		return sharedby;
	}
	object* getlikedby()
	{
		return *likedby;
	}
	char* getpostid()
	{
		return id;
	}
	char* gettext()
	{
		return text;
	}
	Date getshareddate()
	{
		return shareddate;
	}
	void settext(char*addtext)
	{

		text = Helper::GetStringFromBuffer(addtext);
	}
	void setshareddate(Date d)
	{
		shareddate.setdate(d.getday(), d.getmonth(), d.getyear());
	}
	virtual ~post()//destructor
	{
		delete id;
		delete text;
		for (int i = 0; i < noofcomments; i++)
		{
			delete comments[i];
		}
		delete[] comments;
		delete sharedby;
		delete Activity;
		for (int i = 0; i, noOflikes; i++)
		{
			delete likedby[i];
		}
		delete[] likedby;
	}
};

class page :public object// public inheritance from class object
{
	post** timeline;
	char* id;
	char* title;
	int postno;
public:
	page()//constructor
	{
		postno = 0;
		timeline = new post * [10];
		id = 0;
		title = 0;
	}
	void ReadDataFromFile(fstream& finpage)
	{
		char tempbuffer[80];
		finpage >> tempbuffer;

		id = Helper::GetStringFromBuffer(tempbuffer);
		finpage.getline(tempbuffer, 80);
		title = Helper::GetStringFromBuffer(tempbuffer);

	}
	void viewpostlikes()//displays the likes of a post
	{
		char postid[] = "post5";
		for (int i = 0; i < postno; i++)
		{
			if (Helper::Compare(timeline[i]->getpostid(), postid))//compares the postid and displays the specific post likes
			{
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Command:                                                " << "ViewLikedlist" << "(" << timeline[i]->getpostid() << ")" << endl;

				cout << "Post Liked By:" << endl;
				timeline[i]->viewlikedby();
			}

		}
	}
	void viewpage()//displays the posts of a page
	{
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                   ViewPage(p1)" << endl;
		for (int i = 0; i < postno; i++)
		{
			
				timeline[i]->viewposts();
			

		}
		
	}

	void viewnames()
	{
		cout <<title;
	}
	void addtotimeline(post* ptr)
	{
		timeline[postno] = ptr;
		postno++;
	}
	char* getid()
	{
		return id;
	}
	char* getpagetitle()
	{
		return title;
	}
	void viewpageposts()
	{
		for (int i = 0; i < postno; i++)
		{
			timeline[i]->viewposts();
		}
	}
	void viewselectedpost(post*ptr)
	{
	

		for (int i = 0; i < postno; i++)
		{
			if (timeline[i]==ptr)
			{
				timeline[i]->viewposts();
			}
			
		}
	}

	~page(){//destructors
		delete id;
		delete title;
	}
};

class memory :public post {//public inheritance from class post
	post* sharedpost;
public:
	memory()//constructor
	{
		sharedpost =0;
	}
	memory(post* ptr, char* text, object* sharer) :post()
	{
		sharedpost = ptr;
		setsharedby(sharer);
		settext(text);
		setshareddate(Date::current_date.getcurrentdate());
	}
	void addmemory(post* ptr, char* text, object* sharer)
	{
		sharedpost = new memory;
		sharedpost = ptr;
		setsharedby(sharer);
		settext(text);
		setshareddate(Date::current_date.getcurrentdate());

	}
	void viewposts()
	{
		Date today = Date::getcurrentdate();
		Date sharedadte = sharedpost->getshareddate();
		cout << "~~~~";
		getsharedby()->viewnames();
		cout << "shared a memory~~~~";
		Date::getcurrentdate().viewdate();
		cout << gettext();
		cout << endl;
		cout << "                                          ";
		cout << "(" << today.getyear() - sharedadte.getyear() << "Years Ago" << ")" << endl;
		
	}
	~memory()//destructor
	{
		sharedpost = 0;
	}
};
class user:public object
{
	char* id;
	char* firstname;
	char* lastname;
	user** friendlist;
	page** likedpages;
	int nooffriends;
	int nooflikedpages;
	post** timeline;
	int noofposts;
public:
	user()//constructor
	{
		id = 0;
		firstname = 0;
		lastname = 0;
		friendlist = new user * [10];
		likedpages = new page * [10];
		nooffriends = nooflikedpages = 0;
		timeline = new post * [10];
		noofposts = 0;
	}
	 char* getid()
	{
		return id;
	}
	 char* getusername()
	{
		return firstname;
	}
	void ReadDataFromFile(fstream& finuser)//takes input from file
	{
		char tempfirstname[10];
		char templastname[10];
		char tempid[10];
		finuser >> tempid;
		id = Helper::GetStringFromBuffer(tempid);
		finuser >> tempfirstname;
		firstname = Helper::GetStringFromBuffer(tempfirstname);
		finuser >> templastname;
		lastname = Helper::GetStringFromBuffer(templastname);

	}
	void Addfriend(user* addedfriend)//takes user pointer and adds to the friendlist of a user 
	{
		friendlist[nooffriends] = addedfriend;
		nooffriends++;

	}
	
	void viewnames()
	{
		cout << firstname << " " << lastname << " ";
	}
	
	void likedpage(page* pgptr)
	{

		likedpages[nooflikedpages] = pgptr;
		nooflikedpages++;
	}
	
	void viewlikedpages()
	{
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                               " << "View Liked Pages" << endl;
		cout << this->firstname << " " << this->lastname << "                               liked pages:" << endl;
		for (int i = 0; i < nooflikedpages; i++)
		{
			cout << likedpages[i]->getid() << " " << likedpages[i]->getpagetitle() << endl;
		}
	}
	void view()
	{
		cout << id << "  " << firstname << " " << lastname << endl;
	}
	void viewfriendlist()
	{
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                   " << "View FriendList" << endl;
		cout << this->firstname << " " << this->lastname << "                              FriendList:" << endl;
		for (int i = 0; i < nooffriends; i++) {
			friendlist[i]->view();

		}
	}
	
	void viewhomepage()
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                   " << "View Home" << endl;
		cout << this->firstname << " " << this->lastname << "                       -HomePage" << endl;
		for (int i = 0; i < nooffriends; i++) {
			friendlist[i]->viewpost();

		}
		for (int i = 0; i < nooflikedpages; i++)
		{
	
			likedpages[i]->viewpageposts();
		}
		
	}

	void viewpost()
	{
		cout << this->firstname << " " << this->lastname << " " << endl;

		for (int i = 0; i < noofposts; i++)
		{

			timeline[i]->viewposts();
		}

	}
	void viewtimeline()
	{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                   " << "View Timeline" << endl;
		cout << this->firstname << " " << this->lastname << "                              -Timeline" << endl;
		
		for (int i = 0; i < noofposts; i++)
		{
			
			post* p = timeline[i];
			Date postdate = p->getshareddate();
			if (postdate.getday() == Date::current_date.getday()|| postdate.getday() == Date::current_date.getday()-1 && postdate.getmonth() == Date::current_date.getmonth() && postdate.getyear() == Date::current_date.getyear())
			{
				timeline[i]->viewposts();
			}
		}
	}

	int CompareStrings(char str1[], char str2[])
	{

		if (str1[0] != str2[0] || str1[1] != str2[1])
			return true;
		else
			return false;
	}
	void viewpostlikes()
	{
		char postid[] = "post5";
			for (int i = 0; i < noofposts; i++)
			{
				if (Helper::Compare(timeline[i]->getpostid(), postid))
				{
					cout << "Command:                                                " << "ViewLikedlist" << "(" << timeline[i]->getpostid() << ")" << endl;
					
					cout << "Post Liked By:" << endl;
					timeline[i]->viewlikedby();
				}
				
			}
	}

	void addtotimeline(post*ptr)//adds post to timeline
	{
		timeline[noofposts] = ptr;
		noofposts++;
	}
	void viewselectedpost(post* ptr)
	{
		for (int i = 0; i < noofposts; i++)
		{
			if (timeline[i] == ptr)//if post address matches the post address in timeline
			{

				timeline[i]->viewposts();
			}

		}
	}
	void viewmemories()
	{
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                                    SeeYourMemories() " << endl;
		this->viewnames();
		cout << "                             Memories" << endl;
		cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << endl;
		
		for (int i = 0; i < noofposts; i++)
		{
			post* p = timeline[i];
			Date postdate = p->getshareddate();
			if (postdate.getday() == Date::current_date.getday() && postdate.getmonth() == Date::current_date.getmonth() && postdate.getyear() != Date::current_date.getyear())
			{
				cout << "On this day" << endl;
				cout << Date::current_date.getyear() - postdate.getyear() << " Years Ago" << endl;
				timeline[i]->viewposts();
			}

		}
	}
	void addmemorytotimeline(memory*toaddmemory)
	{
		
		noofposts++;
		post** temp = nullptr;
		if(timeline)
		temp=timeline;
		timeline = new post * [noofposts];
		timeline[0] = toaddmemory;
		
		if (temp)
		{
			for (int i = 0; i < noofposts; i++)//deep copies the data back into timeline from 1 index onwards
			
				timeline[i+1] = temp[i];
			delete[]temp;
			
		}
		
	}
	void sharedmemory(post* ptr, char* addtext)
	{
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                  ShareMemory(post10, Never thought I will be specialist in this field)" << endl;
		cout << "Command:                  View TimeLine" << endl;
		object* sharer = ptr->getsharedby();
		memory* mptr = new memory;
		mptr->addmemory(ptr, addtext,sharer);//stores data inmemroy
	this->addmemorytotimeline(mptr);//then adds it to timeline
	
	for (int i = 0; i<noofposts; i++)//displayes timeline with added memory
	{
		timeline[i]->viewposts();
		}

	}
	~user()//destructor
	{
		delete id;
		delete firstname;
		delete lastname;
		for (int i=0; i < nooffriends; i++)
			delete[] friendlist[i];
		delete[] friendlist;
		for (int i=0; i < nooflikedpages; i++)
			delete[] likedpages[i];
		delete[] likedpages;
	}
};
class facebook
{
	comment** comments;
	page** pages;
	user** users;
	post** posts;
	char*** tempfriendlist;
	user* ptr;
	page* ptr1;
	post* ptr2;
	object* ptr3;
	char* tempsharedby;
	char* templikedby;
	char* commentid;
	char* cmby;

public:
	facebook()//constructor
	{
		comments = new comment * [13];
			for (int i = 0; i < 13; i++)
			{
				comments[i] = new comment[13];
			}
		pages = new page * [12];
		for (int i = 0; i < 10; i++)
		{
			pages[i] = new page[10];
		}
		users = new user * [20];
		for (int i = 0; i < 10; i++)
		{
			users[i] = new user[10];
		}
		posts = new post * [11];
		for (int i = 0; i < 6; i++)
		{
			posts[i] = new post[10];
		}
		ptr = 0;
		ptr1 = 0;
		ptr2 = 0;
		ptr3 = 0;
		tempfriendlist = new char** [20];
		commentid = 0;
		cmby = 0;
	}
	void loadpages(fstream& finpage)//function for loading pages data by calling its data read function
	{
		int totalpages = 0;
		finpage >> totalpages;
		pages = new page * [totalpages];
		for (int i = 0; i < totalpages; i++)
		{
			pages[i] = new page;
			pages[i]->ReadDataFromFile(finpage);

		}


	}
	int CompareStrings(char str1[], char str2[])
	{

		if (str1[0] != str2[0] || str1[1] != str2[1])
			return true;
		else
			return false;
	}
	void loadcomments(fstream& fincomments)//function for loading comments by allocating memory and calling data read functions
	{
		int totalcomments = 0;
		fincomments >> totalcomments;
		comments = new comment * [totalcomments];
		int i = 0;
		while (!fincomments.eof())
		{
			comments[i] = new comment;
			char temp[20];
			fincomments >> temp;
			commentid = Helper::GetStringFromBuffer(temp);
			comments[i]->ReadDataFromFile1(fincomments);
			temp[0] = '\0';
			char arr[2] = "u";
			fincomments >> temp;
			if (temp[0] == arr[0])
			{
				ptr3 = searchuserbyid(temp);
				comments[i]->commentbyy(ptr3);
			}
			else {
				ptr3 = searchpagebyid(temp);
				comments[i]->commentbyy(ptr3);
			}
			comments[i]->ReadDataFromFile(fincomments);
			i++;
		}
		int j = 0;
		while (j< totalcomments) {
			
			post* ptr = searchpostbyid(comments[j]->getpostid());//returns the address of the post
			ptr->addcommentstopost(comments[j]);//adds comment to the post pointer
			j++;
		}
	}
	void loadusers(fstream& finuser)//loading users by allocating memory and calling further loading functions
	{
		int totalusers = 0;
		finuser >> totalusers;
		users = new user * [totalusers];
		for (int i = 0; i < totalusers; i++)
		{
			users[i] = new user;
			users[i]->ReadDataFromFile(finuser);

			char tempbuffer[50];
			char error[] = "-1";
			tempfriendlist[i] = new char* [10];
			finuser >> tempbuffer;
			int j = 0;
			while (CompareStrings(tempbuffer, error))
			{
				tempfriendlist[i][j] = Helper::GetStringFromBuffer(tempbuffer);
				j++;
				finuser >> tempbuffer;
			}
			tempfriendlist[i][j] = NULL;


			finuser >> tempbuffer;
			while (CompareStrings(tempbuffer, error))//adds likedpages to user data
			{
				ptr1 = searchpagebyid(tempbuffer);
				users[i]->likedpage(ptr1);
				finuser >> tempbuffer;

			}

		}

		for (int i = 0; i < totalusers; i++)//adds friend to a user
		{
			for (int j = 0; tempfriendlist[i][j] != NULL; j++)
			{
				ptr = searchuserbyid(tempfriendlist[i][j]);
				users[i]->Addfriend(ptr);
			}
		}


	}
	void loadposts(fstream &finpost)
	{
		int totalposts = 0;
		finpost >> totalposts;
		posts = new post * [totalposts];
		int i = 0;
		while (!finpost.eof())
		{
			posts[i] = new post;
			posts[i]->ReadDataFromFile(finpost);

			char temp[10];
			finpost >> temp;
			tempsharedby = Helper::GetStringFromBuffer(temp);

			char user[] = "u";

			if (tempsharedby[0] == user[0])
			{
				object* objptr = searchuserbyid(tempsharedby);
				posts[i]->setsharedby(objptr);
				objptr->addtotimeline(posts[i]);
			}
			else
			{object* objptr = searchpagebyid(tempsharedby);
			posts[i]->setsharedby(objptr);
			objptr->addtotimeline(posts[i]);
		}
				
				char error[] = "-1";
				char tempbuffer[20];
				finpost >> tempbuffer;
				while (CompareStrings(tempbuffer, error))
				{
					templikedby = Helper::GetStringFromBuffer(tempbuffer);
					if (tempbuffer[0]==user[0])
					{
						object* objptr = searchuserbyid(templikedby);
						posts[i]->setlikedby(objptr);
						
					}
					else {
						object* objptr = searchpagebyid(templikedby);
						posts[i]->setlikedby(objptr);
					}
					finpost>> tempbuffer;
				}
				i++;
		}
	}
	void load_data(const char* pagefile, const char* userfile,const char* postfile,const char*commmentfile)//takes file names and calls their loading
	{


		fstream finpage;
		finpage.open("Page.txt");
		if (finpage)
			this->loadpages(finpage);
		finpage.close();
		fstream finuser;
		finuser.open("User.txt");
		if (finuser)
			this->loadusers(finuser);
		finuser.close();
		fstream finpost;
		finpost.open("Post.txt");
		this->loadposts(finpost);
		finpost.close();
		fstream fincomment;
		fincomment.open("Comment.txt");
		this->loadcomments(fincomment);
		fincomment.close();


	}
	page* searchpagebyid(const char* pgid)//returns the page id address
	{

		for (int i = 0; i < 12; i++)
		{
			if (Helper::Compare(pages[i]->getid(), pgid))
			{

				return pages[i];
			}
		}

	}
	post* searchpostbyid(const char* postid)//returns the post id address
	{

		for (int i = 0; i < 11; i++)
		{
			if (Helper::Compare(posts[i]->getpostid(), postid))
			{
				return posts[i];
			}
		}

	}

	user* searchuserbyid(const char* userid)//returns the user id address
	{
		for (int i = 0; i < 20; i++)
		{
			if (Helper::Compare(users[i]->getid(), userid))
			{
				return users[i];
			}
		}
	}
	void run()
	{
	
		
		user* currentuser = searchuserbyid("u7");
		currentuser->viewfriendlist();
		currentuser->viewlikedpages();
		currentuser->viewtimeline();
		currentuser->viewhomepage();
		page* p = searchpagebyid("p1");
		p->viewpostlikes();
		post* p1 = searchpostbyid("post5");
		p1->setlikedby(currentuser);
		p->viewpostlikes();
		//adding comment
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                            PostComment(post4, Good Luck for your Result)" << endl;
		cout << "Command:                   ViewPost(post4) " << endl;
		comment* cm;
		cm = new comment;
		char temp[] = "Good Luck For Your Result";
		cm->setcomment(temp);
		cm->commentbyy(currentuser);
		post* p2 =searchpostbyid("post4");
		p2->addcommentstopost(cm);
		
		object* obj = p2->getsharedby();
	   obj->viewselectedpost(p2);
		cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Command:                                            PostComment(post5,Thanks for the wishes )" << endl;
		cout << "Command:                   ViewPost(post5) " << endl;
		comment* cm2;
		cm2= new comment;
		char temp2[] = "Thanks for the wishes";
		cm2->setcomment(temp2);
		cm2->commentbyy(currentuser);
		post* p3 = searchpostbyid("post8");
		p3->addcommentstopost(cm2);
		object* obj2 = p3->getsharedby();
		obj2->viewselectedpost(p3);
		currentuser->viewmemories();
		post* pointer = searchpostbyid("post10");
		char text[] = "Never thought I will be specialist in this field";
		currentuser->sharedmemory(pointer, text);
		page* pageptr = searchpagebyid("p1");
		pageptr->viewpage();
	}
	~facebook()//destructor
	{
		
		for (int i = 0; i < 12; i++)
		{
			delete pages[i];

		}
		delete[] pages;
		for (int i = 0; i < 20; i++)
		{
			delete users[i];
		}
		delete[] users;
		delete[] tempfriendlist;
		for (int i = 0; i<13; i++)
		{
			delete[] comments[i];
		}
		delete[] comments;
		for (int i = 0;i<12; i++)
		{
			delete[] posts[i];
		}
		delete[]posts;
		
		delete ptr;
		delete ptr1;
		delete ptr2;
		delete ptr3;
		delete tempsharedby;
		delete templikedby;
		delete commentid;
		delete cmby;

	}
	

};

int main()
{
	facebook fb;
	fb.load_data("Page.txt", "User.txt","Post.txt","Comment.txt");
	Date::current_date.setdate(15, 11, 2017);
fb.run();
	system("pause");
	return 0;
}
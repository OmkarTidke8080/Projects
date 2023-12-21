import java.util.*;

class Program
{
    public static void main(String arg[])
    {
      DBMS obj = new DBMS();
      obj.StartDBMS();
     
      /* 
      obj.InserIntoTable("Rahul", 29, 72);
      obj.InserIntoTable("Sagar", 25, 89);
      obj.InserIntoTable("Pooja", 21, 56);
      obj.InserIntoTable("Sayali", 23, 68);
      obj.InserIntoTable("Tejas", 29, 85);

      obj.SelectFrom();
      obj.SelectFrom(4);
      obj.SelectFrom("Rahul");

      System.out.println("maximum marks are : "+obj.Aggregate_Max());
      System.out.println("Minimum marks are : "+obj.Aggregate_Min());
      System.out.println("Sum of marks are : "+obj.Aggregate_Sum());
      System.out.println("Average of marks are : "+obj.Aggregate_Avg());

      obj.DeleteFrom(4);
      obj.SelectFrom();
      */
    }
}

class DBMS
{
    public LinkedList <Student> lobj;  // reference of linked list class

    public DBMS()
    {
        lobj = new LinkedList<Student>();
    }
    public void  StartDBMS()
    {
        System.out.println("DBMS Started Successfully...");
        System.out.println("Table Schema Created Successfully...");
       
        String Query;
        String Tokens[];

        Scanner sobj  = new Scanner(System.in);
        int TokensCount = 0;
        while(true)
        {
         System.out.println("Marvellous DBMS : ");
         Query = sobj.nextLine();

         Tokens = Query.split(" ");

         TokensCount = Tokens.length;

         if(TokensCount == 1)
         {
            if("exit".equals(Tokens[0]))
            {
                System.out.println("ThankYou For Using Marvellous DBMS...");
                break;
            }
         }
         else if(TokensCount == 2)
        {

        }
        else if(TokensCount == 3)
        {

        }
         else if(TokensCount == 4)
        {
            if("select".equals(Tokens[0]))
            {
                SelectFrom();
            }
        }
         else if(TokensCount == 5)
        {
            if("select".equals(Tokens[0]))
            {
                if("MAX".equals(Tokens[1]))
                {
                    System.out.println("Maximum marks is : "+Aggregate_Max());
                }
                else if("MIN".equals(Tokens[1]))
                {
                        System.out.println("Minimum marks is : "+Aggregate_Min());

                }
                else if("AVG".equals(Tokens[1]))
                {
                       System.out.println("Average marks is : "+Aggregate_Avg());
                 
                }
                else if("SUM".equals(Tokens[1]))
                {
                     System.out.println("Sum of marks is : "+Aggregate_Sum());
                   
                }
            }
        }
         else if(TokensCount == 6)
        {
            
        }
         else if(TokensCount == 7)
        {
            if("insert".equals(Tokens[0]))
            {
              InserIntoTable(Tokens[4],Integer.parseInt(Tokens[5]),Integer.parseInt(Tokens[6]));
            }
            else if("delete".equals(Tokens[0]))
            {
                DeleteFrom(Integer.parseInt(Tokens[6]));
            }
        }

        }
    }
            // Insert into table values(------,-------,-----);


    public void InserIntoTable(String Name, int Age, int Marks)
    {
      Student sobj = new Student(Name,Age,Marks);
      lobj.add(sobj); // data gets added at the end
    }

    // Select * from student
    public void SelectFrom()
    {
        System.out.println("Record from the  student table are : ");

        for(Student sref : lobj)  // for each loop
        {
            sref.Display();
        }
    }

    // select * student where RNo = 11;
     public void SelectFrom(int no)
    {
        System.out.println("Record from the  student table are : ");

        for(Student sref : lobj)  // for each loop
        {
            if(sref.Rno == no)
            {
            sref.Display();
            break;
            }
        }
    }

     // select * student where Name = "Rahul";
     public void SelectFrom(String str)
    {
        System.out.println("Record from the student table are : ");

        for(Student sref : lobj)  // for each loop
        {
            if(str.equals(str))
            {
            sref.Display();
            break;
            }
        }
    }

    // Select MAX(marks) from student;
    public int Aggregate_Max()
    {
        Student temp = lobj.get(0);
        int iMax = temp.Marks;

        for(Student sref : lobj)  // for each loop
        {
            if(sref.Marks > iMax)
            {
              iMax = sref.Marks;
            }
        }
        return iMax;
    }

     // Select MIN(marks) from student;

    public int Aggregate_Min()
    {
        Student temp = lobj.get(0);

        int iMin = temp.Marks;

        for(Student sref : lobj)  // for each loop
        {
            if(sref.Marks < iMin)
            {
              iMin = sref.Marks;
            }
        }
        return iMin;
    }

         // Select SUM(marks) from student;

     public int Aggregate_Sum()
    {
       int iSum = 0;

        for(Student sref : lobj)  // for each loop
        {
            iSum = iSum + sref.Marks;
        }
        return iSum;
    }

     // Select AVG(marks) from student;
     public float Aggregate_Avg()
    {
       int iSum = 0;

        for(Student sref : lobj)  // for each loop
        {
            iSum = iSum + sref.Marks;
        }
        return (iSum/(lobj.size()));
    }
    
  // delete  from student where RNo = 2
  public void DeleteFrom(int no)
  {
    int i = 0;

    for(Student sref : lobj)
    {
      if(sref.Rno == no)
      {
        lobj.remove(i);
        break;
      }
      i++;
    }
  }

  // 
}

class Student
{
    public int Rno;
    public String Name;
    public int Age;
    public int Marks;

    public static int Generator;  // Its not a inbild concept

    static
    {
        Generator = 0;
    }

    public Student( String str, int X, int Y)
    {
       this.Rno = ++Generator;
       this.Name = str;
       this.Age = X;
       this.Marks = Y;
    }

    public void Display()
    {
        System.out.println(this.Rno + " "+ this.Name + " "+ this.Age + " " +this.Marks);
    }

}

// Insert Query
// insert into student values Rahul 24 67
//   0      1     2       3      4   5  6
// No of tokens :  7

// Select Query
// Select * from student
//   0    1   2     3
// No of tokens : 4

// delete from student where Rno = 4
//   0     1     2      3    4  5 6
// No of tokens : 7

// select Max Age from student
//   0     1    2   3    4
// No of Tokens : 5

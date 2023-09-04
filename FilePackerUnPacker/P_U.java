import java.util.*;
import java.io.*;

public class P_U {
    public static void main(String args[]) 
    {
       Scanner sc= new Scanner (System.in);
       int choice ;
       int temp = 1;
       while(temp == 1){
        System.out.println("1.Packing  2.Unpacking 3.Exit");
       System.out.println("Enter your choice:");
       choice = sc.nextInt();
       switch(choice){
        case 1:
          Packer();
          break;
          
        case 2:
        UnPacker();
        break;

        case 3:
        temp = 0;
        break;
       }
       }
       
      
    } 
    
    public static void Packer(){
         byte Buffer[] = new byte[1024];
        int iRet = 0;
        boolean bRet;
        int PackCount = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("--------Marvellous Packer UnPacker----------");
        System.out.println("Packing activity of the application is started...");
        System.out.println("Enter the  name of folder which contains the file sthat you want to pack : ");
        String FolderName = sobj.nextLine();

        File fobj = new File(FolderName);
        String Header = null;

        System.out.println("Enter the name of packed file you want to createe : ");
        String PackFile = sobj.nextLine();

    try
    {
        File Packobj = new File( PackFile);
        bRet =  Packobj.createNewFile();
        
        if(bRet == false)
        {
          System.out.println("Unabel to create packed file");
          return;
        }

        System.out.println("Packed File gets Successfully create in Your current directory");


        FileOutputStream outobj = new FileOutputStream(Packobj);

        bRet = fobj.isDirectory();
       if(bRet == true)
       {
         File list[] = fobj.listFiles();

         System.out.println("Total Number of files Found in the directory are : "+list.length);

        for(int i = 0; i < list.length; i++)
        {
          if( (list[i].getName()).endsWith(".txt")) // filter
          {
          Header = list[i].getName() + " " + list[i].length();
          for( int j = Header.length(); j < 100; j++)
          {
            Header = Header + " ";
          }
            byte[] bHeader = Header.getBytes();  // convert into bytes
            outobj.write(bHeader,0,bHeader.length);

            FileInputStream inobj = new FileInputStream(list[i]);

            // loop to write the data

            while((iRet = inobj.read(Buffer))  != -1)
            {
               outobj.write(Buffer,0,iRet);
            }

            System.out.println("File Successfully Packed with Name : "+list[i].getName());
            
            inobj.close();

            PackCount++;
          }
        }

        System.out.println("------------Packing Summary------------ : ");
        System.out.println("Total Number of files Scanned : "+list.length);
        System.out.println("Total number of files packed : "+PackCount);

        System.out.println("ThankYou For Using Marvellous Packer UnPcker...");
    }
  }
    catch(Exception iobj)
    {
       System.out.println("Exception Occured : "+iobj);
    }
    }


    public static  void UnPacker(){
         Scanner scobj = new Scanner(System.in);
        byte Header[] = new byte[100];
        int iRet = 0;
        String HeaderStr;
        String Tokens[];
        int iCount = 0;

        System.out.println("----------- Marvellous Packer Unpacker ----------- ");
        System.out.println("Unpacking Actvity of the appication is started...");

        System.out.println("Enter the file name which contains the packed data : ");
        String PackFile = scobj.nextLine();

        try
        {
            File Packobj = new File(PackFile);
            FileInputStream inobj = new FileInputStream(Packobj);

            while((iRet = inobj.read(Header,0,100)) > 0)
            {
                HeaderStr = new String(Header);
                System.out.println(HeaderStr);

                Tokens = HeaderStr.split(" ");

                File newfileobj = new File(Tokens[0]);
                newfileobj.createNewFile();

                FileOutputStream outobj = new FileOutputStream(newfileobj);
                int FileSize = Integer.parseInt(Tokens[1]);
                byte Buffer[] = new byte [FileSize];

                inobj.read(Buffer,0, FileSize);
                outobj.write(Buffer,0,FileSize);

                System.out.println("File successfully extrated with : "+Tokens[0]);
                iCount++;
            }

         System.out.println("------------UnPacking Summary------------ : ");
        System.out.println("Total Number of files Extracted : "+iCount);
        System.out.println("ThankYou For Using Marvellous Packer UnPcker...");
        }
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }
}



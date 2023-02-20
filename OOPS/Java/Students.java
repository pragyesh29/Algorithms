import java.util.*;
class Student{
    int roll_number;
    String name;
    double marks;
    char gender;
    String course;

    // Default constructor
    Student(){
        roll_number = 0;
        name = "";
        marks = 0.0d;
        gender = '\u0000';
        course = "";
    }

    // Paramerterized constructor
    Student(int rno, String n, double mm, char sex, String course){
        this.roll_number = rno;
        this.name = n;
        this.marks = mm;
        this.gender = sex;
        this.course = course;
    }

    // Member function to display details of each student
    private void getDetails(){
        System.out.println("Roll number : " + roll_number); 
        System.out.println("Name : " + name);
        System.out.println("Marks : " + marks);
        System.out.println("Gender : " + gender);
        System.out.println("Course : " + course);
    }

    // Driver
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students : ");
        int n = sc.nextInt();
        Student obj[] = new Student[n];
        for(int i = 0; i < n; i++){
            int rno;
            String nae, c;
            double mm;
            char g;
            System.out.println("Enter roll number : ");
            rno = sc.nextInt();
            System.out.println("Enter name : ");
            nae = sc.nextLine();
            System.out.println("Enter marks : ");
            mm = sc.nextDouble();
            System.out.println("Enter course : ");
            c = sc.nextLine();
            System.out.println("Enter gender : ");
            g = sc.nextLine().charAt(0);
            obj[i] = new Student(rno, nae, mm, g, c);
            obj[i].roll_number = sc.nextInt();
            obj[i].name = sc.nextLine();
            obj[i].marks = sc.nextDouble();
            obj[i].gender = sc.next().charAt(0);
            obj[i].course = sc.nextLine();
            obj[i].getDetails();
        }
    }
}
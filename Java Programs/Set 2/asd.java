import java.text.*;
import java.util.*;

class Student {
	private String name;
	private float percentage;
	public Student (String name, float percentage) {
		this.setName(name);
		this.setPercentage(percentage);;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getPercentage() {
		return percentage;
	}
	public void setPercentage(float percentage) {
		this.percentage = percentage;
	}
	@Override 
	public String toString() {
		return "{\"" + this.name + "\", " + this.percentage + "}";
	}
}

class Sorting implements Comparator<Student>{
	@Override
	public int compare (Student s1, Student s2) {
		return s1.getName().compareTo(s2.getName());
	}
}

class School{
	ArrayList<Student> studentList;
	public void sortByName() {
		Collections.sort(studentList, new Sorting());
	}
	public double getAvgPercentage() {
		double sum = 0;
		for (int i = 0; i < studentList.size(); i++) {
			sum = sum + studentList.get(i).getPercentage();
		}
		return (sum/studentList.size());
	}
	
}
public class Source {
	public static void main(String[] args) {
		ArrayList<Student> list = new ArrayList<>();
		list.add(new Student("Steve", (float)56.3));
		list.add(new Student("Bob", (float)67.3));
		list.add(new Student("Alicia", (float)98.4));
		list.add(new Student("Mark", (float)40));
		
		School x = new School();
		x.studentList = list;
		x.sortByName();
		System.out.println(x.studentList);
		DecimalFormat nf = new DecimalFormat("#.0");
		System.out.println(nf.format(x.getAvgPercentage()));
	}
}
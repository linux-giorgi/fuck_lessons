using System;

class Program
{
    static void Main()
    {
        // Get user input for first name
        Console.Write("Enter your first name: ");
        string firstName = Console.ReadLine();

        // Get user input for last name
        Console.Write("Enter your last name: ");
        string lastName = Console.ReadLine();

        // Display the full name
        Console.WriteLine($"Hello, {firstName} {lastName}!");

        // Manipulate names
        string fullName = firstName + " " + lastName;
        Console.WriteLine("Full name: " + fullName);

        // Display initials
        char firstNameInitial = firstName.Length > 0 ? firstName[0] : ' ';
        char lastNameInitial = lastName.Length > 0 ? lastName[0] : ' ';
        Console.WriteLine("Initials: " + firstNameInitial + lastNameInitial);

        // Uppercase the full name
        string upperCaseFullName = fullName.ToUpper();
        Console.WriteLine("Uppercase full name: " + upperCaseFullName);
    }
}

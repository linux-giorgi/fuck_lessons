import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DevHelpProgram {

    private static Map<String, String> helpTopics;

    static {
        // Initialize help topics
        helpTopics = new HashMap<>();
        helpTopics.put("java", "Java is a high-level, object-oriented programming language.");
        helpTopics.put("python", "Python is an interpreted, high-level, general-purpose programming language.");
        helpTopics.put("html", "HTML (HyperText Markup Language) is the standard markup language for documents designed to be displayed in a web browser.");
        // Add more topics as needed
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to DevHelp!");
        System.out.println("Available topics:");
        helpTopics.keySet().forEach(topic -> System.out.println("- " + topic));

        System.out.print("Enter the topic you need help with: ");
        String selectedTopic = scanner.nextLine().toLowerCase();

        if (helpTopics.containsKey(selectedTopic)) {
            String helpInfo = helpTopics.get(selectedTopic);
            System.out.println("\nHelp on " + selectedTopic + ":");
            System.out.println(helpInfo);
        } else {
            System.out.println("\nTopic not found. Please select a valid topic.");
        }

        scanner.close();
    }
}

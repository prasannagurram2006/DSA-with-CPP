import java.io.*;

// Define the myclass class
class myclass implements Serializable {
    private String s;
    private int i;

    // Constructor
    public myclass(String s, int i) {
        this.s = s;
        this.i = i;
    }

    // Override toString method
    @Override
    public String toString() {
        return "myclass [s=" + s + ", i=" + i + "]";
    }
}

// Define the serializedemo class
public class serializedemo {
    public static void main(String[] args) {
        // Create an object of myclass
        myclass obj = new myclass("Hello, World!", 42);

        // File to store serialized data
        String filename = "myclass.ser";

        // Serialization
        try (FileOutputStream fos = new FileOutputStream(filename);
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            // Serialize the object
            oos.writeObject(obj);
            System.out.println("Object has been serialized: " + obj);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialization
        try (FileInputStream fis = new FileInputStream(filename);
             ObjectInputStream ois = new ObjectInputStream(fis)) {
            // Deserialize the object
            myclass deserializedObj = (myclass) ois.readObject();
            System.out.println("Object has been deserialized: " + deserializedObj);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

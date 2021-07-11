/* Problem 2: Let’s suppose we need to search across 100s of documents (search for words).
   One way to do it is to go one file at a time.
   But that will take too long. So write a multi-threaded or multi-process program
   to run the search across 100s of files. Keep the number of threads/processes configurable.

   Output - files which have the word being searched. */

//The target string can be changed as per requirement
//Path can be changed as well

//I have used one thread per file but it can be configured as per need
//because the performance depends on task and no of threads used.

//To change no. of thread we have to make some changes in main section


import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;


//Implementing thread
class TheThread implements Runnable {

    int counter = 0;

    //Get stream of paths
    //Path can be changed as per requirement

    Stream<Path> streamOfFiles = Files.walk(Paths.get("./src/Multi_tasking/Files"));  // <- Path

    //This list will contain all files in folder
    List<Path> listOfFiles = streamOfFiles.collect(Collectors.toList());

    //Exception
    public TheThread() throws IOException {
    }


    @Override
    public void run()
    {

        //increments counter to access the indexes of the list
        counter++;

        //Calling the method for search file at index counter and  target String
        SearchTextInFiles.lookIn(listOfFiles.get(counter), "target String");
    }
}

public class SearchTextInFiles
{

    //method for searching the target String in file
    public static void lookIn(Path path, String text)
    {
        try
        {
            List<String> texts = Files.readAllLines(path);
            boolean flag = false;

            //Search for string in file
            for (int i = 0; i < texts.size(); i++)
            {
                String str = texts.get(i);

                if (str.contains(text))
                {
                    System.out.println("Found \"" + text + "\" in " + path.getFileName() + " at line : " + (i + 1) + " from thread : " + Thread.currentThread().getName());
                    flag = true;
                }
            }

            if (!flag)
            {
                System.out.println("\"" + text + "\" not found in " + path.getFileName() + " through thread : " + Thread.currentThread().getName());
            }

        }
        catch (IOException e)
        {
            System.out.println("Error while reading " + path.getFileName());
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {

        //Create object of thread class
        TheThread theThread = new TheThread();

        //Get count of files in folder
        int numberOfFiles = theThread.listOfFiles.size() - 1;

        //If folder is empty
        if (numberOfFiles == 0)
        {
            System.out.println("No file found in the folder");
            System.exit(0);
        }

        //List to store threads
        List<Thread> listOfThreads = new ArrayList<>();

        //keeping required number of threads inside the list

        //Here we can change no of threads as per our requirement.

        //change noOfFiles to no of threads required.

        for (int i = 0; i < numberOfFiles; i++)
        {
            listOfThreads.add(new Thread(theThread));
        }

        //starting all the threads
        for (Thread thread :
                listOfThreads)
        {
            thread.start();

        }
    }

}

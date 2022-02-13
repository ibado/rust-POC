import java.util.*;
import java.io.*;

object Words {

    @JvmStatic
    fun countOccurrences(line: String, word: String): Int {
        return line.split(" ").count { w -> w == word }
    }

    @JvmStatic
    fun main(args: Array<String>) {

        val fileName = args[0];
        val word = args[1];

        try {
            var count = 0
            File(fileName).forEachLine { line ->
               count += countOccurrences(line, word)
            }
            
            println("Word was found $count times")

        } catch (exception: FileNotFoundException) {
            println("Error trying to read the file $fileName")
        }
    } 
}

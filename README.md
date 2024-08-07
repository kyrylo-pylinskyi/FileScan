# File Scan
## Application which can be used to search for a string in files

### Description

This application is designed to search for a specified string within files located at a given path. It supports both single files and directories, including recursive traversal of subdirectories. The application outputs results in a specific format to standard output (stdout).

### Input

The application accepts two command line parameters:



* **Path**: Specifies the file or directory to search.
* **String**: The string to be searched for, with a maximum length of 128 characters.
### Output Format

For each occurrence of the string found within files, the application prints:

* **File**: The name of the file where the string was found.
* **Position**: The zero-based offset within the file where the string starts.
* **Prefix**: Up to three characters preceding the matched string.
* **Suffix**: Up to three characters following the matched string.
* _Tabs (\t) and newlines (\n) within the prefix and suffix are printed as literals._

### Error Handling

The application ensures robust error handling and informative error messages for scenarios such as:

* Insufficient command line arguments provided.
* Invalid input path.
* Handling large files to avoid memory constraints.
* Proper handling of exceptions and errors from API functions.

### Multi-Threading Consideration

The solution incorporates multi-threading for concurrent processing of files, aiming to enhance performance by leveraging parallelism. However, it also includes a comparison with a single-threaded solution to evaluate the efficiency gains in different environments, considering factors like drive speed.
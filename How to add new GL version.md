# How to Add a New GL Version

(Note: this is mainly for my reference; I'll try to keep this project up-to-date, so you should never need to do this yourself.)

1. Look for a new specification document (PDF), and add a reference to it in the [README](README.md).
2. Find the minimum values tables.  For OpenGL 4.6, for example, this is §23.53 "Implementation[-]Dependent Values".
3. Copy into a new file of the form "gl&lt;major&gt;.&lt;minor&gt;.txt":
    - Copy *only* the tables' interiors.
    - Copy only tables with a "Minimum Value" column.
    - If the "Get value" token is long (and in-particular if it is split onto two lines), the copy+paste will put the type on the next line.  Something like:<br/>
    ```MAX TESS CONTROL TOTAL OUTPUT COMPONENTS
Z+ GetIntegerv 4096```<br/>
Simply put these on the same line (with a space between) to fix.

4. Open [parse.py](parse.py), edit the lines on the top, and re-run.  This should produce an updated file "[out-cpp.cpp](out-cpp.cpp)", however chances are some (hopefully minor) tweaking of the parser will be required first (I aim to do this for you, for each GL version, first, though).
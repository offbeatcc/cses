(require "asdf")

(defvar *titles*
  '(:c01 "Introduction"
    :c02 "Time Complexity"
    :c03 "Sorting"
    :c04 "Data Structures"
    :c05 "Complete Search"
    :c06 "Greedy Algorithms"
    :c07 "Dynamic Programming"
    :c08 "Amortized Analysis"
    :c09 "Range Queries"
    :c10 "Bit Manipulation"
    :c11 "Basics of Graphs"
    :c12 "Graph Traversal"
    :c13 "Shortest Paths"
    :c14 "Tree Algorithms"
    :c15 "Spanning Trees"
    :c16 "Directed Graphs"
    :c17 "Strong Connectivity"
    :c18 "Tree Queries"
    :c19 "Paths and Circuits"
    :c20 "Flows and Cuts"
    :c21 "Number Theory"
    :c22 "Combinatorics"
    :c23 "Matrices"
    :c24 "Probability"
    :c25 "Game Theory"
    :c26 "String Algorithms"
    :c27 "Square Root Algorithms"
    :c28 "Segment Trees Revisited"
    :c29 "Geometry"
    :c30 "Sweep Line Algorithms"))

(defun extract-string (string start-token end-token)
  "Extract string between start-token and end-token."
  (let* ((start-index (+ (search start-token string) (length start-token)))
         (end-index (search end-token string :start2 start-index)))
    (subseq string start-index end-index)))

(defun replace-string (match replacement string)
  "Replace text between start-token and end-token with replacement-string."
  (let* ((start-index (search match string))
         (end-index (+ start-index (length match))))
    (format nil "~a~a~a" (subseq string 0 start-index)
            replacement (subseq string end-index))))

(defun get-title (key)
  "Read title for the specified key as a string."
  (getf *titles* (intern (string-upcase key) :keyword)))

(defun read-page-title (path)
  "Read content of <title> element from the given HTML page."
  (extract-string (uiop:read-file-string path) "<title>" "</title>"))

(defun write-file-string (pathname content)
  "Write given content to a file."
  (with-open-file (f pathname :direction :output :if-exists :supersede)
    (format f "~a" content)))

(defun book-board-files ()
  "Return the list of board HTML files for book notes."
  (sort (directory "boards/book/c*.html") #'string< :key #'namestring))

(defun problem-board-files ()
  "Return the list of board HTML files for problems."
  (sort (directory "boards/problems/*.html") #'string< :key #'namestring))

(defun chapter-num (chapter-key)
  "Given a chapter key, return the chapter number as a string."
  (string-left-trim "0" (subseq chapter-key 1 3)))

(defun add-book-chapter-html (chapters-html chapter-key chapter-boards-html)
  (format nil "~a
    <li id=\"~a\">Chapter ~a: ~a<a href=\"#~a\"></a>
      <ul>~a
      </ul>
    </li>"
          chapters-html
          chapter-key
          (chapter-num chapter-key)
          (get-title chapter-key)
          chapter-key
          chapter-boards-html))

(defun add-book-board-html (boards-html board-key filename filepath)
  (format nil "~a
        <li id=\"~a\"><a href=\"book/~a\">~a</a></li>"
          boards-html
          board-key
          filename
          (read-page-title filepath)))

(defun add-problem-board-html (boards-html filename filepath)
    (format nil "~a
        <li id=\"~a\"><a href=\"problems/~a\">~a: ~a</a></li>"
          boards-html
          (subseq filename 0 (search "." filename))
          filename
          (subseq filename 0 3)
          (read-page-title filepath)))

(defun chapter-list-html ()
  (let ((filename)
        (previous-chapter-key)
        (chapter-key)
        (board-key)
        (chapters-html "")
        (boards-html ""))
    (dolist (path (book-board-files))
      (format t "~&Found ~a~%" path)
      (setf filename (file-namestring path))
      (setf chapter-key (subseq filename 0 3))
      (setf board-key (subseq filename 0 11))
      ;; Initialize previous-chapter-key to the first chapter-key encountered.
      (unless previous-chapter-key
        (setf previous-chapter-key chapter-key))
      ;; Accumulate HTML for previous chapter's boards when a new
      ;; chapter is found.
      (when (string/= previous-chapter-key chapter-key)
        (setf chapters-html
              (add-chapter-html chapters-html previous-chapter-key boards-html))
        (setf boards-html ""))
      ;; Accumulate HTML for the current board into HTML or boards
      ;; HTML of the current chapter.
      (setf boards-html
            (add-book-board-html boards-html board-key filename path))
      (setf previous-chapter-key chapter-key))
    ;; Accumulate boards HTML for the last chapter.
    (setf chapters-html
          (add-book-chapter-html chapters-html chapter-key boards-html))))

(defun problem-list-html ()
  (let ((boards-html "")
        (filename)
        (board-key))
    (dolist (path (problem-board-files))
      (format t "~&Found ~a~%" path)
      (setf filename (file-namestring path))
      (setf boards-html
            (add-problem-board-html boards-html filename path)))
    boards-html))

(defun main ()
  "Generate boards/index.html"
  (let ((output-html (uiop:read-file-string "meta/boards.html"))
        (output-path "boards/index.html"))
    (setf output-html (replace-string "{{ chapter-list-items }}"
                                      (chapter-list-html)
                                      output-html))
    (setf output-html (replace-string "{{ problem-list-items }}"
                                      (problem-list-html)
                                      output-html))
    (write-file-string output-path output-html)
    (format t "~&Written ~a~%" output-path)))

(main)

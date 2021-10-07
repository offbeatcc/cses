(require "uiop")


;;; Reusable definitions
;;; --------------------

(defun string-starts-with (prefix string)
  "Test that string starts with the given prefix."
  (and (<= (length prefix) (length string))
       (string= prefix string :end2 (length prefix))))

(defun string-inside (mark1 mark2 string &key (start 0))
  "Find string between mark1 and mark2 (exclusive) in string. Start
search for mark1 at start. Return NIL if no such string found."
  (let ((index1)
        (index2))
    ;; Find mark1 in string.
    (setf index1 (search mark1 string :start2 start))
    (unless index1
      (return-from string-inside))
    (incf index1 (length mark1))
    ;; Find mark2 in string.
    (setf index2 (search mark2 string :start2 index1))
    (unless index2
      (return-from string-inside))
    ;; Create result.
    (values (subseq string index1 index2) index1 index2)))

(defun string-between (mark1 mark2 string &key (start 0))
  "Find string between mark1 and mark2 (inclusive) in string. Start
search for mark1 at start. Return NIL if no such string found."
  (let ((index1)
        (index2))
    ;; Find mark1 in string.
    (setf index1 (search mark1 string :start2 start))
    (unless index1
      (return-from string-between))
    ;; Find mark2 in string.
    (setf index2 (search mark2 string :start2 (+ index1 (length mark1))))
    (unless index2
      (return-from string-between))
    ;; Create result.
    (incf index2 (length mark2))
    (values (subseq string index1 index2) index1 index2)))

(defun parse-strings-between (mark1 mark2 string &key (start 0))
  "Return a list of parsed strings along between mark1 and
mark2 (inclusive) along with begin and end indices of the strings in
string."
  (loop
    with result and begin-index and end-index
    do (setf (values result begin-index end-index)
             (string-between mark1 mark2 string :start start))
    while result
    do (setf start end-index)
    collect (list result begin-index end-index)))

(defun strings-between-marks (marks string &key (start 0))
  "Return a list of non-overlapping strings between each pair of
delimiters in marks."
  (let ((parsed (sort (loop for (mark1 mark2) on marks by #'cddr
                            append (parse-strings-between mark1 mark2 string
                                                          :start start))
                      (lambda (x y) (< (second x) (second y))))))
    (loop for entry in parsed
          with end-index = 0
          when (and (<= end-index (second entry)) (<= end-index (third entry)))
            collect (first entry)
          do (setf end-index (third entry)))))

(defmacro add-list-value (key value alist)
  "Add value to a list corresponding to the key in alist."
  `(progn
     (unless (assoc ,key ,alist :test #'string=)
       (push (cons ,key ()) ,alist))
     (push ,value (cdr (assoc ,key ,alist :test #'string=)))))

(defun reverse-cdrs-in-alist (alist)
  (loop for entry in alist
        collect (cons (car entry) (reverse (cdr entry)))))


;;; This Tool
;;; ---------

(defun scrape-html (html)
  (let ((tags (strings-between-marks '("<h2>" "</h2>" "<li " "</a>") html))
        (sections))
    (loop for tag in tags
          with section and href and title
          do (cond ((string-starts-with "<h2>" tag)
                    (setf section (string-inside "<h2>" "</h2>" tag)))
                   (t
                    (setf tag (string-between "<a" "</a>" tag))
                    (setf href (string-inside "href=\"" "\"" tag))
                    (setf title (string-inside "\">" "</a>" tag))
                    (add-list-value section (list href title) sections))))
    (setf sections (reverse sections))
    (setf sections (reverse-cdrs-in-alist sections))
    (pop sections)
    sections))

(defun print-markdown-header ()
  (format t "# Numbered List of Problems from CSES Problem Set

This document contains a numbered list of all the problems from the
[CSES Problem Set](https://cses.fi/problemset/). Two ordinal numbers
are mentioned against each problem. The first number shows the
position of the problem in the entire problem set. The second number
shows the position of the problem within a section.

## Problems

"))

(defun print-markdown-list (sections)
  (let ((overall-total (loop for x in sections sum (length (cdr x)))))
    (loop for (section . problems) in sections
          with i = 1
          do (loop for (href title) in problems
                   and j from 1
                   do (setf href (format nil "https://cses.fi/~a" href))
                      (format t "* ~3,'0d/~d - ~a: ~2,'0d/~d - [~a](~a)~%"
                              i overall-total section j (length problems)
                              title href)
                      (incf i)))))

(defun main ()
  (let* ((html (uiop:read-file-string "/tmp/problemset.html"))
         (sections (scrape-html html)))
    (print-markdown-header)
    (print-markdown-list sections)))

(main)





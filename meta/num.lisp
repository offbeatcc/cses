(defun string-starts-with (prefix string)
  "Test that string starts with the given prefix."
  (and (<= (length prefix) (length string))
       (string= prefix string :end2 (length prefix))))

(defun title-to-slug (title)
  (substitute #\_ #\- (substitute #\_ #\space (string-downcase title))))

(defun filename-to-slug (filename)
  (let* ((delim-index (search "_0" filename))
         (colon-index (search "." filename))
         (end-index (if delim-index delim-index colon-index)))
    (subseq filename 0 end-index)))

(defun read-problems ()
  (with-open-file (f "problemset.lisp")
    (with-standard-io-syntax
      (read f))))

(defun read-filenames ()
  (loop for path in (directory "solutions/*.cc")
        collect (file-namestring path)))

(defun slug-number-map (problems)
  (loop for (n title) in problems
        collect (cons (title-to-slug title) n)))

(defun number-filename (filename slug-number-map)
  (let* ((slug (filename-to-slug filename))
         (num (cdr (assoc slug slug-number-map :test #'string=)))
         (old-path (format nil "solutions/~a" filename))
         (new-path (format nil "~3,'0d_~a" num filename)))
    (cond (num
           (format t "~&renaming ~a -> ~a ...~%" old-path new-path)
           (rename-file old-path new-path))
          (t
           (format t "~&ignored ~a~%" filename)))))

(defun find-and-number (num title filenames)
  (loop for filename in filenames
        when (string= (title-to-slug title) (filename-to-slug filename))
          do (number-filename num filename)
          and collect filename))

(defun main ()
  (let ((slug-number-map (slug-number-map (read-problems))))
    (loop for filename in (read-filenames)
          do (number-filename filename slug-number-map))))

(main)

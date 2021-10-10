(defun string-starts-with (prefix string)
  (and (<= (length prefix) (length string))
       (string= prefix string :end2 (length prefix))))

(defun title-to-slug (title)
  (substitute #\_ #\- (substitute #\_ #\space (string-downcase title))))

(defun filename-to-slug (filepath)
  (let* ((filename (file-namestring filepath))
         (delim-index (search "_0" filename))
         (colon-index (search "." filename))
         (end-index (if delim-index delim-index colon-index)))
    (subseq filename 0 end-index)))

(defun read-problems ()
  (with-open-file (f "problemset.lisp")
    (with-standard-io-syntax
      (read f))))

(defun read-filepaths ()
  (append (directory "solutions/*.cc")
          (directory "solutions/test/*.sh")
          (directory "boards/solutions/*.html")))

(defun slug-number-map (problems)
  (loop for (n title) in problems
        collect (cons (title-to-slug title) n)))

(defun number-filename (filepath slug-number-map)
  (let* ((filename (file-namestring filepath))
         (slug (filename-to-slug filename))
         (num (cdr (assoc slug slug-number-map :test #'string=)))
         (newpath (format nil "~3,'0d_~a" num filename)))
    (cond (num
           (format t "~&renaming ~a -> ~a~%" filepath newpath)
           (rename-file filepath newpath))
          (t
           (format t "~&ignoring ~a~%" filename)))))

(defun main ()
  (let ((slug-number-map (slug-number-map (read-problems))))
    (loop for filepath in (read-filepaths)
          do (number-filename filepath slug-number-map))))

(main)

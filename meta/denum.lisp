(defun read-filenames ()
  (loop for path in (directory "solutions/*.cc")
        collect (file-namestring path)))

(defun denumber-filename (filename)
  (let ((old-path (format nil "solutions/~a" filename))
        (new-path (format nil (subseq filename 4))))
    (format t "~&renaming ~a -> ~a ...~%" old-path new-path)
    (rename-file old-path new-path)))

(defun check-and-denumber-file (filename)
  (cond ((and (every #'digit-char-p (loop for i in '(0 1 2)
                                          collect (char filename i)))
              (char= (char filename 3) #\_))
         (denumber-filename filename))
        (t
         (format t "~&ignored ~a~%" filename))))

(defun main ()
  (loop for filename in (read-filenames)
        do (check-and-denumber-file filename)))

(main)

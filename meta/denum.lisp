(defun read-filepaths ()
  (append (directory "code/*.cc")
          (directory "code/test/*.sh")
          (directory "boards/problems/*.html")))

(defun filename-numbered-p (filepath)
  (let ((filename (file-namestring filepath)))
    (and (every #'digit-char-p (loop for i in '(0 1 2)
                                     collect (char filename i)))
         (char= (char filename 3) #\_))))

(defun denumber-filename (filepath)
  (let ((newpath (format nil (subseq (file-namestring filepath) 4))))
    (format t "~&renaming ~a -> ~a~%" filepath newpath)
    (rename-file filepath newpath))
  )

(defun check-and-denumber-file (filepath)
  (cond ((filename-numbered-p filepath)
         (denumber-filename filepath))
        (t
         (format t "~&IGNORING ~a~%" filepath))))

(defun main ()
  (loop for filename in (read-filepaths)
        do (check-and-denumber-file filename)))

(main)

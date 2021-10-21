(require "asdf")

(defun time-p (s)
  (and (>= (length s) 5)
       (digit-char-p (char s 0))
       (digit-char-p (char s 1))
       (char= (char s 2) #\:)
       (digit-char-p (char s 3))
       (digit-char-p (char s 4))))

(defun change-time (time-string delta-minutes)
  (let ((time (+ (* 60 (parse-integer (subseq time-string 0 2)))
                 (parse-integer (subseq time-string 3 5)))))
    (setf time (mod (+ time delta-minutes) 1440))
    (multiple-value-bind (hours minutes) (truncate time 60)
      (format nil "~2,'0d:~2,'0d" hours minutes))))

(defun trim-whitespace (s)
  (string-trim '(#\Space #\Newline #\Backspace #\Tab 
                 #\Linefeed #\Page #\Return #\Rubout) s))

(defun main ()
  (let* ((text (uiop:read-file-string "chat.txt"))
         (lines (uiop:split-string text :separator '(#\newline)))
         (name)
         (message-index)
         (messages)
         (time))
    (dolist (line lines)
      (cond ((time-p line)
             (setf time (change-time line -330))
             (dolist (message (reverse messages))
               (setf message (trim-whitespace message))
               (unless (zerop (length message))
                 (format t "~&~a ~a: ~a~%" time name message)))
             (setf messages nil)
             (setf name nil))
            (name
             (setf message-index (search " says:" line))
             (setf message-index
                   (if message-index (+ message-index (length " says:")) 0))
             (push (subseq line message-index) messages))
            (t
             (setf name line))))))

(main)

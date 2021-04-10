;; TODO: duncan@bayne.id.au: make the Buildpack aware of the app package name
(in-package #:cl-user)

(hunchentoot:define-easy-handler (root :uri "/") ()
  (cl-who:with-html-output-to-string (s nil :prologue t)
    (:html
      (:body
        (loop for (link . title) in '(("https://x.sanchezcarlosjr.com/github" . "GitHub")
                                ("https://sanchezcarlosjr.com/research" . "Projects")
                                ("http://x.sanchezcarlosjr.com/youtube" . "YouTube"))
        do (htm (:a :href link
                  (:b (str title)))
                :br))
        (:img :src "lisp-logo120x80.png")))))

(defvar *acceptor* nil)

(defun initialize-application (&key port)
  (setf hunchentoot:*dispatch-table*
    `(hunchentoot:dispatch-easy-handlers
       ,(hunchentoot:create-folder-dispatcher-and-handler
          "/" "/app/static/")))

  (when *acceptor*
    (hunchentoot:stop *acceptor*))

  (setf *acceptor*
    (hunchentoot:start (make-instance 'hunchentoot:easy-acceptor :port port))))

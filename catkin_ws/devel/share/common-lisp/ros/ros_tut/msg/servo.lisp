; Auto-generated. Do not edit!


(cl:in-package ros_tut-msg)


;//! \htmlinclude servo.msg.html

(cl:defclass <servo> (roslisp-msg-protocol:ros-message)
  ((first
    :reader first
    :initarg :first
    :type cl:fixnum
    :initform 0)
   (second
    :reader second
    :initarg :second
    :type cl:fixnum
    :initform 0)
   (third
    :reader third
    :initarg :third
    :type cl:fixnum
    :initform 0))
)

(cl:defclass servo (<servo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <servo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'servo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_tut-msg:<servo> is deprecated: use ros_tut-msg:servo instead.")))

(cl:ensure-generic-function 'first-val :lambda-list '(m))
(cl:defmethod first-val ((m <servo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_tut-msg:first-val is deprecated.  Use ros_tut-msg:first instead.")
  (first m))

(cl:ensure-generic-function 'second-val :lambda-list '(m))
(cl:defmethod second-val ((m <servo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_tut-msg:second-val is deprecated.  Use ros_tut-msg:second instead.")
  (second m))

(cl:ensure-generic-function 'third-val :lambda-list '(m))
(cl:defmethod third-val ((m <servo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_tut-msg:third-val is deprecated.  Use ros_tut-msg:third instead.")
  (third m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <servo>) ostream)
  "Serializes a message object of type '<servo>"
  (cl:let* ((signed (cl:slot-value msg 'first)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'second)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'third)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <servo>) istream)
  "Deserializes a message object of type '<servo>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'first) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'second) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'third) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<servo>)))
  "Returns string type for a message object of type '<servo>"
  "ros_tut/servo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'servo)))
  "Returns string type for a message object of type 'servo"
  "ros_tut/servo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<servo>)))
  "Returns md5sum for a message object of type '<servo>"
  "a857454193b3801feabc5fd6d0dba368")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'servo)))
  "Returns md5sum for a message object of type 'servo"
  "a857454193b3801feabc5fd6d0dba368")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<servo>)))
  "Returns full string definition for message of type '<servo>"
  (cl:format cl:nil "int16 first~%int16 second~%int16 third~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'servo)))
  "Returns full string definition for message of type 'servo"
  (cl:format cl:nil "int16 first~%int16 second~%int16 third~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <servo>))
  (cl:+ 0
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <servo>))
  "Converts a ROS message object to a list"
  (cl:list 'servo
    (cl:cons ':first (first msg))
    (cl:cons ':second (second msg))
    (cl:cons ':third (third msg))
))

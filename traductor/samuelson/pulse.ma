[top]
components : pulse@Pulse 
out : outt
in : start stop in_value in_hours in_minutes in_seconds in_milliseconds

link : start start@pulse
link : stop stop@pulse

link : in_value in_value@pulse
link : in_hours in_hours@pulse
link : in_minutes in_minutes@pulse
link : in_seconds in_seconds@pulse
link : in_milliseconds in_milliseconds@pulse

link : out@pulse outt

[cell]
% In ports
in: in_port_in1 in_port_in2 in_port_in3
% Out ports
out: out_port_out1 out_port_out2 out_port_out3
% Input connections
% Output connections
% Internal connections
link: out_port_in1@self in_port_in@(0,0,0)
link: out_port_in2@self in_port_in@(0,1,2)
link: out_port_in3@self in_port_in@(2,2,2)
link: out_port_out@(0,0,0) in_port_out1@self
link: out_port_out@(0,1,2) in_port_out2@self
link: out_port_out@(2,2,2) in_port_out3@self
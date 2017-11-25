Visualization ipython notebook for CD++ logs.
------------------------------------------------

Requirements: python 2.7 and pip.

1. Install the python requirements.txt as following:
    
    pip2 install -r requirements.txt

1. open jupyter notebook

    jupyter notebook

1. Open the notebook named: CD++ Logs parsing and plotting.ipynb

1. Run and enjoy


How does it work?
----------------------

The python code reads from the logs located in teacuplogs.
First finds its entry point in head_log. This file has the pointers to every other logfile.

Then it parses the logfiles looking for Y messages.
This is extracted to a pandas dataframe and processed for visualization.

The three type of plots are:

* A heat map that shows the amount of messages classified by type and model.
* A Letterplot (similar to a boxplot on steroids) with the intermediate values that come out from the models. By each model.
* An Scatterplot that shows the evolution by time and value of the outputs of a particular model.

Look for the image files in img directory to see some examples of the expected outcome.




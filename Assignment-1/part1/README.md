Always throw out the line if there is something that is misformed when defining the schema. When returning the items, 
we will return missing for lines where something is not formatted correctly.

Special cases:
We do not consider <<> or other iterations similar to this one to be valid. The characters '<' and '>' can only be considered a string if inside of the double quotes. 

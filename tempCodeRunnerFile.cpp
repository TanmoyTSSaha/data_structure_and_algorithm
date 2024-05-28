vector<int> hash[arr.size()+1] = {0};

    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]] = 1;
    }
    
    for (int i = 0; i < arr.size(); i++)
    {
        if(hash[i] == 0) return i;
    }
    
    return arr.size()+1
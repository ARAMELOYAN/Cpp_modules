void PmergeMe::InsertionSort(std::vector<int>& vec)
{
	std::vector<int>::iterator it = vec.begin() + 1;
	std::vector<int>::iterator jt;
	while (it < vec.end())
	{
		jt = it;
		while (jt > vec.begin())
		{
			if (jt > jt - 1)
				break ;
			swap(jt--);
		}
		++it;
	}
}

void PmergeMe::swap(std::vector<int>::iterator it)
{
	int tmp;
	tmp = *it;
	*it = *(it - 1);
	*(it - 1) = tmp;
}

void PmergeMe::Merge(std::vector<int>& vec, std::vector<int>& vec1, std::vector<int>& vec2)
{
	vec.erase(vec.begin(), vec.end());
	std::vector<int>::iterator it1 = vec1.begin();
	std::vector<int>::iterator it2 = vec2.begin();
	while (it1 < vec1.end() && it2 < vec2.end())
	{
		if (*it1 < *it2)
			vec.push_back(*(it1++));
		else
			vec.push_back(*(it2++));
	}
	if (it1 == vec1.end())
		while (it2 < vec2.end())
			vec.push_back(*(it2++));
	else
		while (it1 < vec1.end())
			vec.push_back(*(it1++));
}

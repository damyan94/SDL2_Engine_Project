#pragma once

class ITableColumn
{
public:
	ITableColumn() = default;
	virtual ~ITableColumn() = default;

	virtual size_t GetCellsCount() const = 0;
	virtual bool HasCell(size_t index) const = 0;
	virtual void RemoveCell(size_t index) = 0;

	virtual std::vector<size_t> Sort(bool ascending = true) = 0;
	virtual void Sort(const std::vector<size_t>& indices, bool ascending = true) = 0;
};

template <typename T>
class TableColumn
	: public ITableColumn
{
public:
	TableColumn() = default;
	~TableColumn() = default;

	size_t GetCellsCount() const final
	{
		return m_Data.size();
	}

	bool HasCell(size_t index) const final
	{
		return index < m_Data.size();
	}

	const T* GetCell(size_t index) const
	{
		AssertReturnIf(!HasCell(index), nullptr);
		return &m_Data[index];
	}

	size_t FindCell(const T& cellData) const
	{
		for (size_t i = 0; i < m_Data.size(); i++)
		{
			ReturnIf(cellData == m_Data[i], i);
		}

		return -1;
	}

	void SetCell(size_t index, const T& cellData)
	{
		AssertReturnIf(!HasCell(index));
		m_Data[index] = cellData;
	}

	void AddCell(const T& cellData)
	{
		m_Data.push_back(cellData);
	}

	void InsertCell(size_t index, const T& cellData)
	{
		AssertReturnIf(!HasCell(index));
		m_Data.insert(m_Data.begin() + index, cellData);
	}

	void RemoveCell(size_t index) final
	{
		AssertReturnIf(!HasCell(index));
		m_Data.erase(m_Data.begin() + index);
	}

	std::vector<size_t> Sort(bool ascending = true) final
	{
		const auto cellsCount = GetCellsCount();

		std::vector<size_t> indices(cellsCount);
		for (size_t i = 0; i < indices.size(); i++)
		{
			indices[i] = i;
		}

		std::sort(indices.begin(), indices.end(), [&](size_t a, size_t b)
			{
				const auto& valA = m_Data[a];
				const auto& valB = m_Data[b];
				return ascending ? (valA < valB) : (valA > valB);
			});

		Sort(indices, ascending);

		return indices;
	}

	void Sort(const std::vector<size_t>& indices, bool ascending = true) final
	{
		const auto cellsCount = GetCellsCount();
		AssertReturnIf(cellsCount != indices.size());

		std::vector<T> sortedData(cellsCount);
		for (size_t i = 0; i < cellsCount; i++)
		{
			sortedData[i] = m_Data[indices[i]];
		}

		m_Data = std::move(sortedData);
	}

private:
	std::vector<T> m_Data;
};

class Table
{
public:
	Table() = default;
	~Table() = default;

	void AddColumn(const std::string& columnName, std::unique_ptr<ITableColumn> column);
	bool HasColumn(const std::string& columnName) const;
	void RemoveColumn(const std::string& columnName);
	ITableColumn* GetColumn(const std::string& columnName);

	template <typename T>
	TableColumn<T>* GetColumn(const std::string& columnName)
	{
		return dynamic_cast<TableColumn<T>*>(GetColumn(columnName));
	}

	void Sort(const std::string& columnName, bool ascending = true);

	static void Test();

private:
	std::unordered_map<std::string, std::unique_ptr<ITableColumn>> m_Data;
};
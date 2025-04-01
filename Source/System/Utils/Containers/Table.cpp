#include "stdafx.h"

#include "System/Utils/Containers/Table.h"

void Table::AddColumn(const std::string& columnName, std::unique_ptr<ITableColumn> column)
{
	AssertReturnIf(HasColumn(columnName));
	m_Data[columnName] = std::move(column);
}

void Table::RemoveColumn(const std::string& columnName)
{
	AssertReturnIf(!HasColumn(columnName));
	m_Data.erase(columnName);
}

ITableColumn* Table::GetColumn(const std::string& columnName)
{
	AssertReturnIf(!HasColumn(columnName), nullptr);
	return m_Data[columnName].get();
}

bool Table::HasColumn(const std::string& columnName) const
{
	return m_Data.contains(columnName);
}

void Table::Sort(const std::string& columnName, bool ascending)
{
	AssertReturnIf(!HasColumn(columnName));
    auto* sortColumn = GetColumn(columnName);

    std::vector<size_t> indices = sortColumn->Sort();
    
    for (auto& [name, column] : m_Data)
    {
		ContinueIf(columnName == name);
		
		column->Sort(indices, ascending);
    }
}

void Table::Test()
{
	Table table;
	table.AddColumn("ID", std::make_unique<TableColumn<int32_t>>());
	table.AddColumn("Name", std::make_unique<TableColumn<std::string>>());
	table.AddColumn("Age", std::make_unique<TableColumn<uint32_t>>());

	auto colId = dynamic_cast<TableColumn<int32_t>*>(table.GetColumn("ID"));
	colId->AddCell(1);
	colId->AddCell(2);
	colId->AddCell(3);

	auto colName = table.GetColumn<std::string>("Name");
	auto cellsCount = colName->GetCellsCount();
	auto a = colName->HasCell(1);
	colName->AddCell("Damyan");
	colName->AddCell("Svetlana");
	colName->AddCell("Gencho");
	cellsCount = colName->GetCellsCount();
	a = colName->HasCell(1);
	auto b = colName->GetCell(a);

	auto colAge = dynamic_cast<TableColumn<uint32_t>*>(table.GetColumn("Age"));
	colAge->AddCell(30);
	colAge->AddCell(26);
	colAge->AddCell(4);

	auto idDamyan = colName->FindCell("Damyan");
	auto ageDamyan = *colAge->GetCell(idDamyan);
	colAge->SetCell(idDamyan, ++ageDamyan);

	auto idPencho = colName->FindCell("Pencho");
	auto agePencho = colAge->GetCell(idPencho);

	colName->InsertCell(colName->FindCell("Gencho"), "Henry");
	colName->RemoveCell(colName->FindCell("Gencho"));

	table.Sort("Age", true);
}
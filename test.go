package main

import (
	"database/sql"
	"fmt"
)

type Currency struct {
	ID        uint         `db:"id" json:"id"`
	Name      string       `db:"name" json:"name"`
	Code      string       `db:"code" json:"code"`
	CreatedAt sql.NullTime `db:"createdAt" json:"createdAt"`
	UpdatedAt sql.NullTime `db:"updatedAt" json:"updatedAt"`
}

type temp struct {
	Currency map[string]Currency
}

func (cr Currency) String() string {
	return fmt.Sprintf("%v", cr.ID)
}

func main() {
	c := Currency{}
	fmt.Println(c)
}

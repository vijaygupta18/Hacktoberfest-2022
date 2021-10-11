import styled from "styled-components";
import React, { useEffect, useState } from "react";
import "./Transaction.css";

const TransactionCell = (props) => {
  return (
    <div>
      {props.payload?.type === "EXPENSE" ? (
        <div className="cell red" >
        <span>{props.payload?.desc}</span>
        <span>${props.payload?.amount}</span>
      </div>
      ) : (<div className="cell green" >
      <span>{props.payload?.desc}</span>
      <span>${props.payload?.amount}</span>
    </div>)}
      
    </div>
  );
};
const TransactionsComponent = (props) => {
  const [searchText, updateSearchText] = useState("");
  const [filteredTransaction, updateTxn] = useState(props.transactions);

  const filterData = (searchText) => {
    if (!searchText || !searchText.trim().length) {
      updateTxn(props.transactions);
      return;
    }
    let txn = [...props.transactions];
    txn = txn.filter((payload) =>
      payload.desc.toLowerCase().includes(searchText.toLowerCase().trim())
    );
    updateTxn(txn);
  };

  useEffect(() => {
    filterData(searchText);
  }, [props.transactions]);

  return (
    <div className="t-container">
      Transactions
      <input
        placeholder="Search"
        onChange={(e) => {
          updateSearchText(e.target.value);
          filterData(e.target.value);
        }}
      />
      {filteredTransaction?.map((payload) => (
        <TransactionCell payload={payload} />
      ))}
    </div>
  );
};
export default TransactionsComponent;

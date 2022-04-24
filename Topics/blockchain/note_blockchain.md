# Technical characteristics
1991: timestamp and prevent tampering with past data

## Distributed ledger - "block link"
- data
- hash
- pre. block hash
## Genesis block - first block
## Hash
## P2P - peer-to-peer

## Proof-of-work
- Slowdown creation of new block
- To in a sense, prolong the time it takes to tamper with all of the previous blocks in a chain
- Miners/mining to compete who gets the new hash first, cause some problem
	- mainly electricity consumption rate
	- mining pools: centralization, mining favors the one that spent more on their equipments
## Proof-of-stake
- No miners, but instead validators, by an election process
	- security deposit: validators need to put munnies (stake) into a pot before being selected as validators
	- chance of being chosen increases linearily with the size of stake (favor the rich? less than PoW)
- Minting / Forging new block
	- reward associates with the fee inside the new block
	- stake needs to be higher than the reward, to ensure financially responsibility
	- lose the stake with fraudant act
- 51% attack

---
# Applications

## Keeping track of data, records
- Medical records, e-notary, munnies, transaction
- In car: prevent chaning of the diometers
- Intellectual documents
- Digital voting
	- identify
	- account for malware devices
	- no attacks, securities
- Food industry: track food records

## Smart contracts
- Tiny computer programs live on the blockchain, and can be executed when certain conditions are met
- Eg. NFT
	- non-fungible-token
	- but it's weird xD proves of ownership but doesn't own the physical copy say of a picture, its creator can still sell copies of it
	- contains link to IPFS (interplanetary file storage, bit like bit-torrent, decentralized the internet)

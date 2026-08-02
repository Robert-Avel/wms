# Categorias

- Item
- Volume
- Carga
- Armazem
- Endereços

## Item
  Registro dos tipos de produtos existentes e seus detalhes

## Volume
  Representa um item fisico

## Lote
  Um lote é um grupo de volumes, associados na hora da criação ou destino

## Carga
  É uma coleção de Volumes individuais ou por "Lotes"

## Armazem
  É a representação virtual de uma unidade de um armazem

## Endereços
  São unidades de conteiners menores que armazenam volumes


# Comandos
  Iniciando com `./bin...`


`item new <name> <weight> <cubic> <value>`
`item info <id>`
`item list <page>`
`item search <name>`

`volume new <item_id>`
`volume get <id>`
`volume search batch <batch>`
`volume search item <item_id>`
`volume list <page>`

`batch list <page>`
`batch new <item_id>...`

`cargo new volume <volume_id>...`
`cargo new batch <batch_id>...`
`cargo list <page>`


`warehouse new <name> <cubic>`
`warehouse list <page>`
